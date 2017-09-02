#include <iostream>

#include "World.h"
#include "Entity.h"

int main() {
    World world("./worlds/default.so", 0, 0);
    world.CreateEntity("./entities/default.so");
    for (int i = 0; i < 10; ++i) {
        world.Update();
    }
    return 0;
}
