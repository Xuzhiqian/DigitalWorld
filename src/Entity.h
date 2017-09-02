#ifndef ENTITY_H
#define ENTITY_H

#include <functional>

#include "Action.h"

class Entity {
    public:
        Entity(const char *name);
        ~Entity();

        Action Act();

        void SetPosi(int x, int y);

        std::function<int(int, int)> SenseEnergy;
        std::function<int(int, int)> SenseHeight;
        std::function<void(int&, int&)> SensePosition;

    private:
        int energy;
        int posiX, posiY;

        void (*init)(Entity &entity);
        Action (*act)(Entity &entity);

        
        friend class World;
};

#endif
