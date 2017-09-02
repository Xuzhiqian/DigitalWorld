#ifndef ENTITY_H
#define ENTITY_H

#include "Action.h"

class Entity {
    public:
        Entity(const char *name);
        ~Entity();
        Action Act();

        int energy;
        int posiX, posiY;
        void SetPosi(int x, int y);
        void (*init)(Entity *entity);
        Action (*act)(Entity *entity);
};

#endif
