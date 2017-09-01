#ifndef WORLD_H
#define WORLD_H

#include <string>

class World {
    public:
        World(std::String name);
        ~World();
        Update();
    private:
        int time;
};

#endif
