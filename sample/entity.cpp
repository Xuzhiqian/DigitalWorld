#include "../src/utils.h"
#include "../src/EntityAPI.h"

extern "C" void init(Entity *entity) {
    log("default entity initialized");
}

extern "C" void act(Entity *entity) {
    log("default entity acted");
}
