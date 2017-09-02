#include <iostream>
using namespace std;

#include "World.h"
#include "Entity.h"

void ShowWorld(const World *world) {
    for (int i = 0; i < world->sizeX; ++i) {
        for (int j = 0; j < world->sizeY; ++j) {
            putchar(world->grids[i][j].occupied?'X':'O');
        }
        putchar('\n');
    }
    for (auto e: world->entities) {
        cout << e.energy << endl;
    }
}

int main() {
    World world("./worlds/default.so");
    world.CreateEntity("./entities/default.so");
    while(true) {
        world.Update();
        ShowWorld(&world);
        getchar();
    }
    return 0;
}
