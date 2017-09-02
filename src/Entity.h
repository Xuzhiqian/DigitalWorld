#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
    public:
        Entity(const char *name);
        ~Entity();
        void Act();
    private:
        int energy;
        int posi_x, posi_y;
        void (*init)(Entity *entity);
        void (*act)(Entity *entity);
};

#endif
