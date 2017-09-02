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
        void CreateEntity(const char *name);
        int getMaxX() const;
        int getMaxY() const;
        vector< vector<Grid> > grids;
    private:
        int time;
        int max_x, max_y;
        void (*init)(World *world);
        void (*update)(World *world);
        vector<Entity> entities;
};

#endif
