#ifndef WORLD_H
#define WORLD_H

#include <string>

class World {
    public:
        World(const char *name);
        ~World();
        void Update();
    private:
        int time;
        void (*update)(World *world);
};

#endif
