"""This is the simulator."""

import sys
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5 import QtCore
import math

import world as wd


class MonitorConfig:
    monitor_size = (1280, 960)
    grid_width = 50
    grid_height = 50
    grid_boarder_color = (0, 0, 0)

    @staticmethod
    def grid_fill_color(h):
        tmp = int(255/(1+math.exp(-h/10)))
        return tmp, tmp, tmp

    @staticmethod
    def energy_fill_color(e):
        return 0, 0, max(0, min(e*10, 255))

    entity_boarder_color = (0, 0, 255)
    entity_fill_color = (255, 255, 0)
    redraw_interval = 1000/24
    world_update_interval = 200


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
        self.graphics_scene = QGraphicsScene(self)
        self.timer = QtCore.QTimer(self)

        self.init_ui()

    def init_ui(self):
        self.timer.setInterval(MonitorConfig.redraw_interval)
        self.graphics_view.setGeometry(0, 0, MonitorConfig.monitor_size[0], MonitorConfig.monitor_size[1])
        self.graphics_view.setScene(self.graphics_scene)
        self.redraw()
        # Connect timer and redraw
        self.timer.timeout.connect(self.redraw)
        self.timer.start()

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
                if self.world.energy[x][y] != 0:
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
                                               QBrush(QColor(*MonitorConfig.entity_fill_color))
                                               )


def main():
    app = QApplication(sys.argv)
    world = wd.World("default", ["default"]*3)
    m = Monitor(world)
    m.show()

    world_thread = WorldThread(world)
    world_thread.start()

    sys.exit(app.exec_())


if __name__ == '__main__':
    main()
