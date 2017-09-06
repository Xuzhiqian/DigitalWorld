"""This is a default world for test as well as tutorial.

You should implement two functions named 'init' and 'update' to define the behavior of your world.
'init' is called when the world is initialized.
'update' is called again and again when the world is running.
In both functions above, you are provided a world interface('wi' for short), call its methods to get and set the status
of the world.

Available methods in wi is listed below, the ones marked by * means that you can only call it in 'init':
    * set_size(sx, sy):
        set the size of the world
    get_size():
        return a tuple (size_x, size_y)
    set_height(x, y, h):
        set the height at (x, y) as h
    get_height(x, y):
        return the height at (x, y)
    set_energy(x, y, e):
        set the energy at (x, y) as e
    get_energy(x, y):
        return the energy at (x, y)
"""

from random import randint

size_x = 10
size_y = 10


def init(wi):
    # You have to set world size
    # Note that wi.set_size is only available here, not in update
    wi.set_size(size_x, size_y)
    # Then set heights and energy
    # Default is all 0
    for y in range(size_y):
        for x in range(size_x):
            wi.set_height(x, y, randint(0, 10))
            wi.set_energy(x, y, x+y)


def update(wi):
    for y in range(size_y):
        for x in range(size_x):
            wi.set_energy(x, y, wi.get_energy(x, y)+1)
