#ifndef WORLD_H
#define WORLD_H

#include <vector>
using namespace std;

#include "Entity.h"

class World {
    public:
        World(const char *name);
        ~World();
        void Update();
        void CreateEntity(const char *name);
    private:
        int time;
        void (*update)(World *world);
        vector<Entity> entities;
};

#endif
