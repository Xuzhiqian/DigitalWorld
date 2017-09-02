#include <dlfcn.h>

#include "World.h"
#include "util.h"

World::World(const char *name, int max_x, int max_y) {
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

int World::getMaxX() const {
    return max_x;
}

int World::getMaxY() const {
    return max_y;
}
