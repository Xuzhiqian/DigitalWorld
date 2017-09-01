#include <string>

#include <dlfcn.h>

#include "World.h"
#include "util.h"

World::World(std::string name) {
    log("World::World called");
}

World::~World() {
}

void World::Update() {
    log("World::Update called");
}
