#include "../src/EntityAPI.h"
#include "../src/Action.h"

#include <cstdlib>

// 初始化时会调用该函数
// 暂时我并不打算让它做什么，但是如果你想
// 的话……
extern "C" void init(Entity &entity) {
}

// 世界每轮更新后依次调用每个entity的该函数
// 你应该获取一些关于这个世界的信息，然后决
// 定要做什么，写在Action变量中（别急，我会
// 告诉你怎么写哒）。之后世界将按照你的要求
// 执行操作。无效的操作将被忽略（如果没有遇
// 到bug的话）。
// 这里完全可以做很多其他的事情，因为你的手
// 上可是完整的C++。
extern "C" Action act(Entity &entity) {
    Action action;

    /*
     * 下面是一些伪代码，目的是告诉你怎样比
     * 较方便地做一些和生存相关的事情，如果
     * 你只是想跑个web服务器就不用看啦。
     */
    // 看看在(x, y)处有多少能量
    int e = entity.SenseEnergy(x, y);
    // 看看(x, y)有多高
    int h = entity.SenseHeight(x, y);
    // 得到你的坐标，结果存入x和y
    SensePosition(x, y);
    // 得到世界的大小
    SenseWorldSize(x, y);

    /*
     * 下面说说Action。
     * action.type指出要进行的行动类型，
     * 目前可取{Move, Eat}中之一。
     * action.param是行动的参数。
     */
    // 移动
    action.type = Move;
    action.param.direction = Up | Down | Left | Right;
    // 吃  掉你所在位置的全部能量（注意可能是负的23333）
    action.type = Eat;

    return action;
}
