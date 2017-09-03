#ifndef ACTION_H
#define ACTION_H

enum ActionType {
    Move, 
    Eat
};

enum Direction {
    Up,
    Down,
    Left,
    Right
};

union ActionParam {
    Direction direction;
};

struct Action {
    ActionType type;
    ActionParam param;
};

#endif
