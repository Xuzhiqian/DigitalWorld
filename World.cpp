#include <string>

#include <dlfcn.h>

#include "World.h"
#include "util.h"

World::World(const char *name) {
    log("World::World called");
    void *handle = dlopen(name, RTLD_LAZY);
    if (!handle) {
        crash(dlerror());
    }
    update = (void(*)(World*))dlsym(handle, "update");
    if (!handle) {
        crash("invalid shared library for world");
    }
}

World::~World() {
}

void World::Update() {
    log("World::Update called");
    update(this);
}
