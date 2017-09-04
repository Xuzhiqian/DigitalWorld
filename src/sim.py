'''This is the simulator.

'''

import world as wd

def main():
    world = wd.World("default", ["default"])
    while True:
        world.update()

if __name__ == '__main__':
    main()
