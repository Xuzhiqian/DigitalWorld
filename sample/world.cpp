#include "../src/utils.h"
#include "../src/WorldAPI.h"

#define MAX_ENERGY 1000
#define MAX_X 10
#define MAX_Y 10

extern "C" void init(World *world) {
    world->SetSize(MAX_X, MAX_Y);
    for (int i = 0; i < MAX_X; ++i) {
        for (int j = 0; j < MAX_Y; ++j) {
            world->SetHeight(i, j, 0);
            world->SetEnergy(i, j, 5);
        }
    }
    log("default world initialized");
}

extern "C" void update(World *world) {
    for (int i = 0; i < MAX_X; ++i) {
        for (int j = 0; j < MAX_Y; ++j) {
            world->SetEnergy(i, j, world->GetEnergy(i, j) + 2);
        }
    }
    log("default world updated");
}
