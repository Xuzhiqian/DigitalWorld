#include <dlfcn.h>

#include "Entity.h"
#include "Action.h"
#include "utils.h"

Entity::Entity(const char *name) {
    void *handle = dlopen(name, RTLD_LAZY);
    if (!handle) {
        crash("failed loading shared library");
    }
    init = (void(*)(Entity*))dlsym(handle, "init");
    act = (Action(*)(Entity*))dlsym(handle, "act");
    if (!handle) {
        crash("invalid shared library for entity");
    }

    init(this);
    this->energy = 0;
}

Entity::~Entity() {
}

Action Entity::Act() {
    return act(this);
}

void Entity::SetPosi(int x, int y) {
    posiX = x;
    posiY = y;
}
