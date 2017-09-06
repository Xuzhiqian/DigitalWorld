"""Define World class."""

import importlib
import random
import functools

import entity
import hyper_param


class WorldInterface:
    pass


class World:
    def __init__(self, world_name, entity_names):
        # Define vars
        self.size = None  # (int, int), the size of the world
        self.entities = None  # [], the entities in the world
        self.energy = None  # [[int]], the energy at each position
        self.height = None  # [[int]], the height at each position
        self.entity = None  # [[entity]], the entity at each position
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
            if e.energy <= 0:
                continue
            e.call_time_limit = hyper_param.default_call_time_limit
            e.act()
            e.energy -= hyper_param.energy_cost_per_update

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
                self.entity[x][y] = en
                break
        en.set_energy(hyper_param.initial_energy())
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
        self.height = [[0 for y in range(sy)] for x in range(sx)]
        self.energy = [[0 for y in range(sy)] for x in range(sx)]
        self.entity = [[None for y in range(sy)] for x in range(sx)]

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

    # @hyper_param.limit_call_times
    def act_eat(self, en):
        x, y = en.pos
        en.set_energy(en.energy+self.energy[x][y])
        self.energy[x][y] = 0

    @hyper_param.limit_call_times
    def act_move_up(self, en):
        x, y = en.pos
        if y == 0 or self.entity[x][y-1] is not None:
            return
        cost = hyper_param.energy_cost_height(self.height[x][y] - self.height[x][y-1])
        if en.energy < cost:
            return
        en.energy -= cost
        en.set_pos(x, y-1)
        self.entity[x][y-1] = en
        self.entity[x][y] = None

    @hyper_param.limit_call_times
    def act_move_down(self, en):
        x, y = en.pos
        if y == self.size[1]-1 or self.entity[x][y+1] is not None:
            return
        cost = hyper_param.energy_cost_height(self.height[x][y] - self.height[x][y+1])
        if en.energy < cost:
            return
        en.energy -= cost
        en.set_pos(x, y+1)
        self.entity[x][y+1] = en
        self.entity[x][y] = None

    @hyper_param.limit_call_times
    def act_move_left(self, en):
        x, y = en.pos
        if x == 0 or self.entity[x-1][y] is not None:
            return
        cost = hyper_param.energy_cost_height(self.height[x][y] - self.height[x-1][y])
        if en.energy < cost:
            return
        en.energy -= cost
        en.set_pos(x-1, y)
        self.entity[x-1][y] = en
        self.entity[x][y] = None

    @hyper_param.limit_call_times
    def act_move_right(self, en):
        x, y=en.pos
        if x == self.size[0]-1 or self.entity[x+1][y] is not None:
            return
        cost = hyper_param.energy_cost_height(self.height[x][y] - self.height[x+1][y])
        if en.energy < cost:
            return
        en.energy -= cost
        en.set_pos(x+1,y)
        self.entity[x+1][y] = en
        self.entity[x][y] = None

    def act_sense_world_size(self, en):
        return self.size

    def act_sense_energy(self, x, y, en):
        return self.energy[x][y]

    def act_sense_height(self, x, y, en):
        return self.height[x][y]

    def act_sense_pos(self, en):
        return en.pos
