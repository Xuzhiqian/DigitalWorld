#ifndef GRID_H
#define GRID_H

#include <vector>
using namespace std;

#include "Entity.h"

class Grid {
    public:
        int energy;
        int height;
        vector<Entity> entities;
    private:
};

#endif
