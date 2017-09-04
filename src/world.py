'''Define World class.

'''

import importlib
import random

import entity
import config

class WorldInterface:
    pass


class World:
    def __init__(self, world_name, entity_names):
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
        '''Do some neccessary initialization, and then call user_init.

        '''
        # No neccerary initialization for now

        # Initialize by user
        self.user_init(self.interface)


    def update(self):
        '''Do some neccessary update, and then call user_update.

        '''
        # Neccessary updates
        self.time += 1

        # Update by user
        self.user_update(self.interface)

        # Let every entity act
        for e in self.entities:
            e.act()


    def create_entity(self, entity_name):
        '''Create an entity by name.

        '''
        en = entity.Entity(entity_name)

        # Set initial position and energy
        # Don't wanna judge if there is any position empty for now
        while True:
            x = random.randint(self.size[0])
            y = random.randint(self.size[1])
            if self.entity[x][y] is None:
                en.set_pos(x, y)
                self.entity[x][y] = True
                break
        en.set_energy(config.initial_energy())
        self.create_entity_interface(en)

        self.entities.append(en)


    def create_entity_interface(self, en):
        en.interface = entity.EntityInterface()

    def set_size(self, sx, sy):
        '''Set world size to (sx, sy) and reset height and energy to 0 at each position.

        '''
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
