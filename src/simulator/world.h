#ifndef WORLD_H
#define WORLD_H

#include <vector>
using namespace std;

#include "grid.h"
#include "entity.h"

class World {
    public:
        World(const char *name);
        ~World();

        void Update();
        int CreateEntity(const char *name);

        void SetSize(int sizeX, int sizeY);
        void SetHeight(int x, int y, int height);
        void SetEnergy(int x, int y, int energy);
        
        void GetSize(int &sizeX, int &sizeY) const;
        int GetHeight(int x, int y) const;
        int GetEnergy(int x, int y) const;
        const vector< Entity > & GetEntities() const;

        bool IsOccupied(int x, int y) const;

   private:
        int sizeX, sizeY;
        vector< vector<Grid> > grids;
        vector< Entity > entities;

        void (*init)(World &world);
        void (*update)(World &world);

        void TakeAction(Entity &entity, Action action);
        void TakeActionMove(Entity &entity, int dx, int dy);
        void TakeActionEat(Entity &entity);
};

#endif
