#include <dlfcn.h>

#include "Entity.h"
#include "Action.h"
#include "utils.h"
#include "config.h"

Entity::Entity(const char *name) {
    void *handle = dlopen(name, RTLD_LAZY);
    if (!handle) {
        crash("failed loading shared library");
    }
    init = (void(*)(Entity&))dlsym(handle, "init");
    act = (Action(*)(Entity&))dlsym(handle, "act");
    if (!handle) {
        crash("invalid shared library for entity");
    }
}

Entity::~Entity() {
}

Action Entity::Act() {
    return act(*this);
}

void Entity::SetPosition(int x, int y) {
    posiX = x;
    posiY = y;
}

void Entity::SensePosition(int &x, int &y) {
    x = posiX;
    y = posiY;
}
