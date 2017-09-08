"""This is the simulator."""

import sys
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5 import QtCore
from PyQt5.Qt import Qt

import world as wd
import hyper_param


class MonitorConfig:
    monitor_size = (960, 960)
    grid_width = 50
    grid_height = 50
    grid_boarder_color = (0, 0, 0)
    height_aprox = hyper_param.height_aprox
    energy_aprox = hyper_param.energy_aprox
    entity_boarder_color = (0, 0, 255)
    redraw_interval = 1000/24
    retable_interval = 1000
    world_update_interval = 50

    @staticmethod
    def grid_fill_color(h):
        tmp = min(abs(h)/2, 127) * (1 if h > 0 else -1) + 128
        return tmp, tmp, tmp

    @staticmethod
    def energy_fill_color(e):
        tmp = abs(e)
        return (min(255, tmp), 0, 0) if e < 0 else (0, 0, min(255, tmp))

    @staticmethod
    def entity_fill_color(en):
        return (255, 0, 0) if en.energy <= 0 else (255, 255, 0)


class WorldThread(QtCore.QThread):
    def __init__(self, world):
        super().__init__()
        self.world = world

    def run(self):
        timer = QtCore.QTimer()
        timer.setInterval(MonitorConfig.world_update_interval)
        timer.timeout.connect(self.single_step)
        timer.start()
        self.exec_()

    def single_step(self):
        self.world.update()


class Monitor(QMainWindow):
    def __init__(self, world):
        super().__init__()
        super().setWindowState(QtCore.Qt.WindowMaximized)

        self.world = world
        self.graphics_view = QGraphicsView(self)
        self.table_view = QTableView(self)
        self.graphics_scene = QGraphicsScene(self)
        self.redraw_timer = QtCore.QTimer(self)
        self.retable_timer = QtCore.QTimer(self)
        self.refresh_time = 0

        self.init_ui()

    def init_ui(self):
        self.redraw_timer.setInterval(MonitorConfig.redraw_interval)
        self.retable_timer.setInterval(MonitorConfig.retable_interval)
        self.graphics_view.setGeometry(0, 0, MonitorConfig.monitor_size[0], MonitorConfig.monitor_size[1])
        self.graphics_view.setScene(self.graphics_scene)
        self.graphics_view.fitInView(0, 0,
                                     self.world.size[0] * 1.3,  # Well, 1.5 is set by experiments
                                     self.world.size[1] * 1.3,  # I don't quite understand this api
                                     Qt.KeepAspectRatio
                                     )
        self.table_view.setGeometry(MonitorConfig.monitor_size[0] + 10,
                                   0,
                                   400,
                                   MonitorConfig.monitor_size[1])
        # Connect timer and redraw
        self.redraw_timer.timeout.connect(self.redraw)
        self.redraw_timer.start()
        self.retable_timer.timeout.connect(self.retable)
        self.retable_timer.start()

    def refresh(self):
        self.redraw()
        self.retable()

    def redraw(self):
        self.graphics_scene.clear()
        # Draw grids
        for y in range(self.world.size[1]):
            for x in range(self.world.size[0]):
                self.graphics_scene.addRect(x * MonitorConfig.grid_width, y * MonitorConfig.grid_height,
                                            MonitorConfig.grid_width, MonitorConfig.grid_height,
                                            QPen(QColor(*MonitorConfig.grid_boarder_color)),
                                            QBrush(QColor(*MonitorConfig.grid_fill_color(self.world.height[x][y])))
                                            )
        # Draw energy
        for y in range(self.world.size[1]):
            for x in range(self.world.size[0]):
                self.graphics_scene.addEllipse(x * MonitorConfig.grid_width + MonitorConfig.grid_width/4,
                                               y * MonitorConfig.grid_height + MonitorConfig.grid_height/4,
                                               MonitorConfig.grid_width / 2, MonitorConfig.grid_height / 2,
                                               QPen(QColor(*MonitorConfig.grid_boarder_color)),
                                               QBrush(QColor(*MonitorConfig.energy_fill_color(self.world.energy[x][y])))
                                               )

        # Draw entities
        for y in range(self.world.size[1]):
            for x in range(self.world.size[0]):
                if self.world.entity[x][y] is None:
                    continue
                self.graphics_scene.addEllipse(x * MonitorConfig.grid_width + 1, y * MonitorConfig.grid_height + 1,
                                               MonitorConfig.grid_width - 2, MonitorConfig.grid_height - 2,
                                               QPen(QColor(*MonitorConfig.entity_boarder_color)),
                                               QBrush(QColor(*MonitorConfig.entity_fill_color(self.world.entity[x][y])))
                                               )

    def retable(self):
        model = QStandardItemModel(self.table_view)
        idx = [QStandardItem(str(i)) for i in range(len(self.world.entities))]
        eng = [QStandardItem(str(e.energy)) for e in self.world.entities]
        model.appendColumn(idx)
        model.appendColumn(eng)
        self.table_view.setModel(model)


def main():
    app = QApplication(sys.argv)

    world = wd.World("default", ["default"]*2)
    m = Monitor(world)
    m.show()

    world_thread = WorldThread(world)
    world_thread.start()

    sys.exit(app.exec_())


if __name__ == '__main__':
    main()
