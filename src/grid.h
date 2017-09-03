#ifndef GRID_H
#define GRID_H

#include <vector>
using namespace std;

#include "entity.h"

class Grid {
    public:
        Grid();

        int energy;
        int height;
        bool occupied;
    private:
};

#endif
