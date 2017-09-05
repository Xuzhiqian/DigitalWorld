# 简介
这是一个沙盒编程游戏。

# 世界观
* 世界(World)大小有限，二维离散坐标；
* 每个坐标具有高度和能量；
* 个体(Entity)拥有能量(Energy)属性和坐标属性；
* 世界不断地更新，个体不断消耗能量；
* 个体可以感知世界的信息，并采取行动(Act)；
* 能量减为0的个体将永久死亡。

# 目标
* 得到足够的能量生存下来；
* 利用full python support做一些有趣的事情。

# 游戏方式
用户通过编写程序控制个体的行动规则，也可以通过编写程序自定义世界的初始化和更新规则。
在[src/worlds/default/](https://github.com/faultrit/DigitalWorld/tree/master/src/worlds/default)及[src/entities/default](https://github.com/faultrit/DigitalWorld/tree/master/src/entities/default)下查看示例。
