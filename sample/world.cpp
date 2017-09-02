#include "../src/utils.h"
#include "../src/WorldAPI.h"

#define MAX_ENERGY 1000

extern "C" void init(World *world) {
    for (int i = 0; i < world->maxX; ++i) {
        for (int j = 0; j < world->maxY; ++j) {
            world->grids[i][j].height = 10;
            world->grids[i][j].energy = 10;
        }
    }
    log("default world initialized");
}

extern "C" void update(World *world) {
    for (int i = 0; i < world->maxX; ++i) {
        for (int j = 0; j < world->maxY; ++j) {
            world->grids[i][j].energy = max(world->grids[i][j].energy+2, MAX_ENERGY);
        }
    }
    log("default world updated");
}
