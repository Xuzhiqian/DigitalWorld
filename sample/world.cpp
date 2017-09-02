#include "../src/utils.h"
#include "../src/World.h"

extern "C" void init(World *world) {
    log("default world initialized");
    for (int i = 0; i < world_get_max_x(world); ++i) {
        for (int j = 0; j < world_get_max_y(world); ++j) {
            world->grids[i][j].energy = 1;
        }
    }
}

extern "C" void update(World *world) {
    for (int i = 0; i < world_get_max_x(world); ++i) {
        for (int j = 0; j < world_get_max_y(world); ++j) {
            world->grids[i][j].energy++;
        }
    }
    log("default world updated");
}
