#include "../src/utils.h"
#include "../src/World.h"

extern "C" void init(World *world) {
    log("default world initialized");
}

extern "C" void update(World *world) {
    log("default world updated");
}
