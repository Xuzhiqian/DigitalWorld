#include <dlfcn.h>

#include "World.h"
#include "util.h"

World::World(const char *name) {
    void *handle = dlopen(name, RTLD_LAZY);
    if (!handle) {
        crash("failed loading shared library");
    }
    update = (void(*)(World*))dlsym(handle, "update");
    if (!handle) {
        crash("invalid shared library for world");
    }
    dlclose(handle);
}

World::~World() {
}

void World::Update() {
    time++;
    update(this);
}
