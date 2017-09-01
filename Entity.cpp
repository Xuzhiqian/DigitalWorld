#include <dlfcn.h>

#include "Entity.h"
#include "util.h"

Entity::Entity(const char *name) {
    void *handle = dlopen(name, RTLD_LAZY);
    if (!handle) {
        crash("failed loading shared library");
    }
    act = (void(*)(Entity*))dlsym(handle, "act");
    if (!handle) {
        crash("invalid shared library for entity");
    }
    dlclose(handle);
}

Entity::~Entity() {
}

void Entity::Act() {
    act(this);
}
