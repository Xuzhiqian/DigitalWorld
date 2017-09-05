"""Define World class."""

import importlib
import random
import functools

import entity
import config


class WorldInterface:
    pass


class World:
    def __init__(self, world_name, entity_names):
        # Define vars
        self.size = None
        self.entities = None
        self.energy = None
        self.height = None
        self.entity = None
        # Construct world interface
        self.interface = WorldInterface()
        self.interface.set_size = self.set_size
        self.interface.get_size = self.get_size
        self.interface.set_height = self.set_height
        self.interface.get_height = self.get_height
        self.interface.set_energy = self.set_energy
        self.interface.get_energy = self.get_energy
        # Load user defined functions
        tmp = importlib.import_module("worlds.{0}.main".format(world_name))
        self.user_init = tmp.init
        self.user_update = tmp.update
        # Initialize the world
        self.init()
        # Delete interfaces that should only be used in initialization
        del self.interface.set_size
        # Create entities
        # It will be appended to self.entities in self.create_entity, so don't worry
        self.entities = []
        for en in entity_names:
            self.create_entity(en)

        self.time = 0

    def init(self):
        """Do some necessary initialization, and then call user_init."""
        # No necessary initialization for now
        #
        # Initialize by user
        self.user_init(self.interface)

    def update(self):
        """Do some necessary update, and then call user_update."""
        # Necessary updates
        self.time += 1
        # Update by user
        self.user_update(self.interface)
        # Let every entity act
        for e in self.entities:
            e.act()

    def create_entity(self, entity_name):
        """Create an entity by name."""
        en = entity.Entity(entity_name)
        # Set initial position and energy
        # Don't wanna judge whether there is any position empty for now
        while True:
            x = random.randint(0, self.size[0]-1)
            y = random.randint(0, self.size[1]-1)
            if self.entity[x][y] is None:
                en.set_pos(x, y)
                self.entity[x][y] = True
                break
        en.set_energy(config.initial_energy())
        self.create_entity_interface(en)
        # Save current entity
        self.entities.append(en)

    def create_entity_interface(self, en):
        en.interface = entity.EntityInterface()

        # For convenience
        def pack(f):
            return functools.partial(f, en=en)
        # Actions
        # I don't think this is a beautiful implementation
        en.interface.move_up = pack(self.act_move_up)
        en.interface.move_down = pack(self.act_move_down)
        en.interface.move_left = pack(self.act_move_left)
        en.interface.move_right = pack(self.act_move_right)
        en.interface.eat = pack(self.act_eat)
        # Sensors
        en.interface.sense_height = pack(self.act_sense_height)
        en.interface.sense_energy = pack(self.act_sense_energy)
        en.interface.sense_world_size = pack(self.act_sense_world_size)
        en.interface.sense_pos = pack(self.act_sense_pos)

    def set_size(self, sx, sy):
        """Set world size to (sx, sy) and reset height and energy to 0 at each position."""
        self.size = (sx, sy)
        self.height = [[0]*sy]*sx
        self.energy = [[0]*sy]*sx
        self.entity = [[None]*sy]*sx

    def get_size(self):
        return self.size

    def set_height(self, x, y, h):
        self.height[x][y] = h

    def get_height(self, x, y):
        return self.height[x][y]

    def set_energy(self, x, y, e):
        self.energy[x][y] = e

    def get_energy(self, x, y):
        return self.energy[x][y]

    def act_eat(self, en):
        pass

    def act_move_up(self, en):
        pass

    def act_move_down(self, en):
        pass

    def act_move_left(self, en):
        pass

    def act_move_right(self, en):
        pass

    def act_sense_world_size(self, en):
        pass

    def act_sense_energy(self, en):
        pass

    def act_sense_height(self, en):
        pass

    def act_sense_pos(self, en):
        pass
