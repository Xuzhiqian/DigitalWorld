#ifndef WORLD_H
#define WORLD_H

#include <vector>
using namespace std;

#include "Grid.h"
#include "Entity.h"

class World {
    public:
        World(const char *name, int max_x, int max_y);
        ~World();
        void Update();
        int maxX, maxY;
        void (*init)(World *world);
        void (*update)(World *world);
        vector< vector<Grid> > grids;
        vector< Entity > entities;
        int CreateEntity(const char *name);
        void TakeAction(Entity entity, Action action);
};

#endif
