#ifndef ENTITY_H
#define ENTITY_H

#include <functional>

#include "Action.h"

class Entity {
    public:
        Entity(const char *name);
        ~Entity();

        std::function<int(int, int)> SenseEnergy;
        std::function<int(int, int)> SenseHeight;
        std::function<void(int&, int&)> SenseWorldSize;

        void SensePosition(int &x, int &y);

    private:
        int energy;
        int posiX, posiY;

        void (*init)(Entity &entity);
        Action (*act)(Entity &entity);

        Action Act();
        void SetPosition(int x, int y);
        
        friend class World;
};

#endif
