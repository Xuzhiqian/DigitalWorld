'''Define Entity class.

'''

import importlib

class EntityInterface:
    pass


class Entity:
    def __init__(self, entity_name):
        # Construct entity interface
        self.interface = EntityInterface()

        # Load user init and act function
        tmp = importlib.import_module("entities.{0}.main".format(entity_name))
        self.user_init = tmp.init
        self.user_act = tmp.act