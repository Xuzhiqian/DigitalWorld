#include <dlfcn.h>

#include "Entity.h"
#include "utils.h"

Entity::Entity(const char *name) {
    void *handle = dlopen(name, RTLD_LAZY);
    if (!handle) {
        crash("failed loading shared library");
    }
    init = (void(*)(Entity*))dlsym(handle, "init");
    act = (void(*)(Entity*))dlsym(handle, "act");
    if (!handle) {
        crash("invalid shared library for entity");
    }
    dlclose(handle);

    init(this);
}

Entity::~Entity() {
}

void Entity::Act() {
    act(this);
}
