#include <iostream>

#include "World.h"
#include "Entity.h"

int main() {
    World world("./worlds/default.so", 0, 0);
    Entity entity("./entities/default.so");
    return 0;
}
