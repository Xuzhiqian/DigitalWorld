"""This is a default world for test as well as tutorial."""

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
            wi.set_height(x, y, 1)
            wi.set_energy(x, y, 10)


def update(wi):
    for y in range(size_y):
        for x in range(size_x):
            wi.set_energy(x, y, wi.get_energy(x, y)+1)
