#include "../src/utils.h"
#include "../src/EntityAPI.h"
#include "../src/Action.h"

#include <iostream>
#include <cstdlib>

static int size_x, size_y;

extern "C" void init(Entity &entity) {
    entity.SenseWorldSize(size_x, size_y);
}

extern "C" Action act(Entity &entity) {
    Action action;
    int x, y;
    entity.SensePosition(x, y);
    if (x > 0) {
        action.type = Move;
        action.param.direction = Left;
    } else {
        action.type = Move;
        action.param.direction = Right;
    }
    return action;
}
