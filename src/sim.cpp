#include <iostream>
using namespace std;

#include "World.h"
#include "Entity.h"

void ShowWorld(const World &world) {
    int sizeX, sizeY;
    world.GetSize(sizeX, sizeY);
    for (int y = 0; y < sizeY; ++y) {
        for (int x = 0; x < sizeX; ++x) {
            putchar(world.IsOccupied(x, y)?'X':'O');
        }
        putchar('\n');
    }
}

int main() {
    World world("./worlds/default.so");
    world.CreateEntity("./entities/default.so");
    while(true) {
        world.Update();
        ShowWorld(world);
        getchar();
    }
    return 0;
}
