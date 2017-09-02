#include <iostream>
using namespace std;

#include "World.h"
#include "Entity.h"

void ShowWorld(const World &world) {
    int sizeX, sizeY;
    world.GetSize(sizeX, sizeY);
    for (int i = 0; i < sizeX; ++i) {
        for (int j = 0; j < sizeY; ++j) {
            putchar(world.IsOccupied(i, j)?'X':'O');
        }
        putchar('\n');
    }
    for (auto e: world.GetEntities()) {
        cout << e.energy << endl;
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
