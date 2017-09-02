#include "../src/utils.h"
#include "../src/WorldAPI.h"

extern "C" void init(World *world) {
    world_get_info(world);
    log("default world initialized");
}

extern "C" void update(World *world) {
    log("default world updated");
}
