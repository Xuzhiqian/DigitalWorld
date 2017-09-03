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

    return 0;
}
