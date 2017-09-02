#include "../src/World.h"

extern "C" void init(World *world) {
    for (int i = 0; i < world->getMaxX(); ++i) {
        for (int j = 0; j < world->getMaxY(); ++j) {
            world->grids[i][j].energy = 1;
        }
    }
}

extern "C" void update(World *world) {
    for (int i = 0; i < world->getMaxX(); ++i) {
        for (int j = 0; j < world->getMaxY(); ++j) {
            world->grids[i][j].energy++;
        }
    }
}
