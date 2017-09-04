'''Define World class.

'''

import config
import entity

class WorldInterface:
    pass

class World:
    def __init__(self, world_name, entity_names):
        # Construct a world interface for initialization
        wi = WorldInterface()
        wi.set_size = self.set_size
        wi.get_size = self.get_size
        wi.set_height = self.set_height
        wi.get_height = self.get_height
        wi.set_energy = self.set_energy
        wi.get_energy = self.get_energy
 
        # Init the world using user defined function
        self.init = __import__("worlds.{0}.init".format(world_name))
        self.init(wi)

        # Create entities
        self.entities = []
        for en in entity_names:
            self.create_entity(en)
        
        # Load the user defined update function
        self.update = __import__("worlds.{0}.update".format(world_name))
    
    
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
    
    
    