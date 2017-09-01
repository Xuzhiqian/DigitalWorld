#include <dlfcn.h>

#include "World.h"
#include "util.h"

World::World(const char *name) {
    void *handle = dlopen(name, RTLD_LAZY);
    if (!handle) {
        crash("failed loading shared library");
    }
    init = (void(*)(World*))dlsym(handle, "init");
    update = (void(*)(World*))dlsym(handle, "update");
    if (!handle) {
        crash("invalid shared library for world");
    }
    dlclose(handle);

    init(this);
}

World::~World() {
}

void World::Update() {
    time++;
    update(this);
}

void World::CreateEntity(const char *name) {
    Entity entity(name);
    entities.push_back(entity);
}
