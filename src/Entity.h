#ifndef ENTITY_H
#define ENTITY_H

#include "Action.h"

class Entity {
    public:
        Entity(const char *name);
        ~Entity();
        Action Act();

        int energy;
        int posi_x, posi_y;
        void (*init)(Entity *entity);
        Action (*act)(Entity *entity);
};

#endif
