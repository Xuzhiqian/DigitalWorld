#include "../src/utils.h"
#include "../src/EntityAPI.h"
#include "../src/Action.h"

#include <cstdlib>

extern "C" void init(Entity &entity) {
    log("default entity initialized");
}

extern "C" Action act(Entity &entity) {
    Action action;
    switch (rand()%2) {
        case 0:
            action.type = Move;
            switch(rand()%4) {
                case 0:
                    action.param.direction = Up;
                    break;
                case 1:
                    action.param.direction = Down;
                    break;
                case 2:
                    action.param.direction = Left;
                    break;
                case 3:
                    action.param.direction = Right;
                    break;
            }
            break;
        case 1:
            action.type = Eat;
            break;
    }
    log("default entity acted");
    return action;
}
