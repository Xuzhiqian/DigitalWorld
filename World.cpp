#include <string>

#include <dlfcn.h>

#include "World.h"
#include "util.h"

World::World(std::String name) {
    log("World::World called");
}

World::Update() {
    log("World::Update called");
}