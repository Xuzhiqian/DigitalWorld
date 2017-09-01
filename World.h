#ifndef WORLD_H
#define WORLD_H

#include <string>

class World {
    public:
        World(std::string name);
        ~World();
        void Update();
    private:
        int time;
};

#endif
