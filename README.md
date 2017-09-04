# 简介
这是一个沙盒编程游戏。

# 世界观
* 世界(World)大小有限，二维离散坐标；
* 每个坐标具有高度和能量；
* 个体(Entity)拥有能量(Energy)属性和坐标属性；
* 世界不断地更新(Update)，每次更新中首先修改世界的状态(每个位置的高度、能量)，然后依次使每个个体行动(Act)。

# 游戏方式
用户通过编写程序控制个体的行动规则，也可以通过编写程序自定义世界的初始化和更新规则。
在[doc](https://github.com/faultrit/DigitalWorld/tree/master/doc)下查看相应的说明。

# 其他
由于时间关系，这个项目将会开发得**非常慢** :)
