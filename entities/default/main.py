"""This is a default entity for test as well as tutorial.

You should implement two functions named 'init' and 'act' to define the behavior of your world.
'init' is called when the entity is initialized.
'act' is called every time the world updates itself.
In both functions above, you are provided an entity interface('ei' for short), call its methods to get information and
perform actions.

Available methods in ei is listed below, unfortunately, you can only call them in 'act':
    sense_world_size():
        return a tuple (size_x, size_y)
    sense_height(x, y):
        return height at (x, y)
    sense_energy(x, y):
        return energy at (x, y)
    sense_pos():
        return current entity's position
    move_up():
    move_down():
    move_left():
    move_right():
        these four functions make current entity move to specific direction by one unit,
        invalid moves will be ignored
    eat():
        eat all the energy in the current position
"""

from numpy import argmax, where
from random import choice


def init(ei):
    pass


def act(ei):
    direction = ['up', 'down', 'left', 'right']

    def foraging():
        x, y = ei.sense_pos()
        energy_around = [0, 0, 0, 0]
        energy_around[2] = (float('-inf') if x == 0
                            else ei.sense_energy(x-1, y))
        energy_around[0] = (float('-inf') if y == 0
                            else ei.sense_energy(x, y-1))
        energy_around[3] = (float('-inf') if x == ei.sense_world_size()[0]-1
                            else ei.sense_energy(x+1, y))
        energy_around[1] = (float('-inf') if y == ei.sense_world_size()[1]-1
                            else ei.sense_energy(x, y+1))
        i = argmax(energy_around)
        return choice([j for j in range(4) if energy_around[j] == energy_around[i]])
    exec('ei.move_'+direction[foraging()]+'()')
    ei.eat()
