#ifndef WORLD_H
#define WORLD_H

#include <vector>
using namespace std;

#include "Grid.h"
#include "Entity.h"

class World {
    public:
        World(const char *name);
        ~World();
        void Update();
        int sizeX, sizeY;
        void (*init)(World *world);
        void (*update)(World *world);
        vector< vector<Grid> > grids;
        vector< Entity > entities;
        int CreateEntity(const char *name);
        void TakeAction(Entity &entity, Action action);
        void SetSize(int sizeX, int sizeY);
        void TakeActionMove(Entity &entity, int dx, int dy);
        void TakeActionEat(Entity &entity);
};

#endif
