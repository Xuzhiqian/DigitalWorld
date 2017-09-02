#include "../src/utils.h"
#include "../src/EntityAPI.h"
#include "../src/Action.h"

#include <iostream>
using namespace std;
#include <cstdlib>

static int size_x, size_y;

extern "C" void init(Entity &entity) {
    entity.SenseWorldSize(size_x, size_y);
}

extern "C" Action act(Entity &entity) {
    Action action;
    int x, y;
    entity.SensePosition(x, y);
    if (y > 0) {
        action.type = Move;
        action.param.direction = Left;
    } else {
        action.type = Move;
        action.param.direction = Right;
    }
    return action;
}
