#ifndef WORLD_H
#define WORLD_H

class World {
    public:
        World(const char *name);
        ~World();
        Update();
    private:
        int time;
};

#endif
