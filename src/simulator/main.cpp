#include <iostream>
using namespace std;

#include "world.h"
#include "utils.h"

int main(int argc, char *argv[]) {
    if (argc <= 2) {
        cout << "Usage: " << argv[0] << " " 
            << "world_name.so" << " "
            << "entity_name.so..." << endl;
        crash("");
    }

    World world(argv[1]);
    for (int i = 2; i < argc; ++i)
        world.CreateEntity(argv[i]);

    while (1)
        world.Update();

    return 0;
}
