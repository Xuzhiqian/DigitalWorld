#include "../src/utils.h"
#include "../src/WorldAPI.h"

// 初始化世界时将调用此函数
extern "C" void init(World &world) {
    // 你必须设置世界的大小
    world.SetSize(max_x, max_y);
    
    // 你可以设置任一位置的高度以及能量
    world.SetHeight(x, y, height);
    world.SetEnergy(x, y, energy);
}

extern "C" void update(World &world) {
    // 你可以设置任一位置的高度以及能量
    // 同上
    
    // 可以查看某个位置是否有Entity，有
    // 的话就把那里的高度调得高高的（划掉）
    bool b = world.IsOccupied(x, y);

    // 可以得到世界的大小，存入x和y，如果你忽然忘了的话
    world.GetSize(x, y);

    // 可以再次设置世界的大小，至于会发生什么……不要问我
}
