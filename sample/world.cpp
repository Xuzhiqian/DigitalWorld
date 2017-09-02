#include "../src/utils.h"
#include "../src/WorldAPI.h"

#define MAX_X 10
#define MAX_Y 5

extern "C" void init(World &world) {
    world.SetSize(MAX_X, MAX_Y);
    for (int i = 0; i < MAX_X; ++i) {
        for (int j = 0; j < MAX_Y; ++j) {
            world.SetHeight(i, j, 0);
            world.SetEnergy(i, j, 2);
        }
    }
}

extern "C" void update(World &world) {
    world.SetEnergy(0, 0, world.GetEnergy(0, 0) + 5);
}
