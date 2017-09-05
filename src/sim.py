"""This is the simulator."""

import world as wd


def show_world(world):
    for y in range(world.size[1]):
        for x in range(world.size[0]):
            print('o' if world.entity[x][y] is None else 'x', end='')
        print()


def main():
    world = wd.World("default", ["default"])
    while True:
        world.update()
        show_world(world)
        input()

if __name__ == '__main__':
    main()
