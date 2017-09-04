'''Define World class.

'''

import importlib
import entity

class WorldInterface:
    pass


class World:
    def __init__(self, world_name, entity_names):
        # Construct a world interface for initialization
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
        del(self.interface.set_size)

        # Create entities
        self.entities = []
        for en in entity_names:
            self.create_entity(en)


    def init(self):
        '''Do some neccessary initialization, and then call user_init.

        '''
        # No neccerary initialization for now

        # Initialize by user
        self.user_init(self.interface)


    def update(self):
        '''Do some necessary update, and then call user_update.
        
        '''
        # No neccerary update for now

        # Update by user
        self.user_update(self.interface)

    
    def set_size(self, sx, sy):
        '''Set world size to (sx, sy) and reset height and energy to 0 at each position.

        '''
        self.size = (sx, sy)
        self.height = [[0]*sy]*sx
        self.energy = [[0]*sy]*sx
    

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
