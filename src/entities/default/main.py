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


def init(ei):
    pass


def act(ei):
    ei.move_up()
