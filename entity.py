"""Define Entity class."""

import importlib


class EntityInterface:
    pass


class Entity:
    def __init__(self, entity_name):
        # Define vars
        self.energy = 0
        self.pos = None
        self.call_time_limit = 0
        # Create entity interface
        # But this will be filled by world
        # It's quite consistent with the reality, right?
        self.interface = EntityInterface()

        # Load user init and act function
        tmp = importlib.import_module("entities.{0}.main".format(entity_name))
        self.user_init = tmp.init
        self.user_act = tmp.act

        # Call user init
        self.user_init(self.interface)

    def act(self):
        self.user_act(self.interface)

    def set_pos(self, x, y):
        self.pos = (x, y)

    def set_energy(self, e):
        self.energy = e
