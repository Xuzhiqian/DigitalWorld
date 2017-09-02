#include <dlfcn.h>

#include "World.h"
#include "utils.h"

World::World(const char *name, int max_x, int max_y) {
    void *handle = dlopen(name, RTLD_LAZY);
    if (!handle) {
        crash("failed loading shared library");
    }
    init = (void(*)(World*))dlsym(handle, "init");
    update = (void(*)(World*))dlsym(handle, "update");
    if (!init || !update) {
        crash("invalid shared library for world");
    }
    this->max_x = max_x;
    this->max_y = max_y;
    
    grids = vector< vector<Grid> >(max_x, vector<Grid>(max_y));
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
