# Math —— 面向对象的专业数学计算库

## 简介

（空）

## Number 库

### real 类

#### 一、简介

以`double`类型数值为分子和分母的分数形式记录数值，拥有已知性标识、有限大标识。由于使用分数的方式记录数值，在数值计算过程中，它有效地规避了计算机内存有限地储存无限循环小数造成的精度损失，因次其运算精度不低于`double`类型。即使拥有更精确的运算和功能，其定义、初始化和使用的方式却与`double`类型几乎完全相同，使用者不会觉得难以接受。不过由于这是一种对象（C++ class），运算效率不及`double`类。

#### 二、使用方式

将 number.h 和 number.lib 放置到项目的同一个文件夹中，调用 real 或 complex 类前包含头文件（如`#include "number.h"`）。运行程序前，把 number.dll 放置在可执行文件（如 example.exe）所在的文件夹里。

#### 三、数据成员

##### （一）公有

- `bool known`已知性标识

##### （二）私有

- `bool finite`有限大标识
- `double denominator`分母
- `double numerator`分子

#### 四、函数

##### （一）构造函数（real.cpp）

- 默认构造函数
- 复制构造函数
- 一个`double`参数的构造函数
- 两个`double`参数的构造函数，分别为分子和分母

##### （二）功能函数（real.cpp）

- `abs()`返回绝对值
- `fabs()`以`double`返回绝对值
- `to_double()`以`double`返回值
- `zero()`判断是否为零
- `infinite()` 判断是否无穷大
- `denominator()`以`double`返回分母
- `numerator()`以`double`返回分子
- `print()`流输出到屏幕

##### （三）操作运算对象本身的函数（object_operation.cpp）

- `reciprocal()`倒数
- `rabs()`变为绝对值
- `add()`增大一个数
- `subtract()`减小一个数
- `multiply()`倍乘一个数
- `divide()`除掉一个数

##### （四）运算符重载（operator.cpp）

下面省略`operator`符号

###### 1. 流输出和读入：

- `<<()`移位重载，输出到流
- `>>()`移位重载，从流读入

###### 2. 特殊处理

- `~()`倒数
- `&()`分子分母分别相加
- `|()`分子分母分别相减

###### 3. 复合赋值

- `+=()`复合加法赋值
- `-=()`复合减法赋值
- `*=()`复合乘法赋值
- `/=()`复合触发赋值

###### 4. 基本运算

- `+()`加法
- `-z()`减法
- `-()`取负
- `*()`乘法
- `/()`除法

###### 5. 逻辑运算

- `==()`判断相等
- `!=()`判断不相等
- `<()`判断小于
- `<=()`判断不大于
- `>()`判断大于
- `>=()`判断不小于

##### （五）`<cmath>`函数重载（rcmath.cpp）

[C 标准库 | 菜鸟教程 (runoob.com)](https://www.runoob.com/cprogramming/c-standard-library-math-h.html)

- `acos()`反余弦
- `asin()`反正弦
- `atan()`反正切
- `atan2()`双参数的反正切
- `cos()`余弦
- `cosh()`双曲余弦
- `sin()`正弦
- `sinh()`双曲正弦
- `tan()`正切
- `tanh()`双曲正切
- `exp(x)`e 的 x 次幂
- `frexp(x, *exponent)`把浮点数分解成尾数和指数，返回尾数，指数存入`exponent`中
- `ldexp(x, exponent)`乘以 2 的`exponent`次幂
- `log()`对数
- `ln()`以 e 为底的对数
- `log2()`以 2 为底的对数
- `log10()`以 10 为底的对数
- `modf(x, *integer)`返回 x 的小数部分，整数部分存入`integer`
- `pow(x, y)`返回 x 的 y 次幂
- `pow2()`平方
- `sqrt()`平方根
- `ceil(x)`不小于 x 的整数值
- `fabs()`绝对值
- `floor(x)`不大于 x 的整数值
- `fmod(x, y)`返回 x 除以 y 的余数

### complex 类

#### 一、简介

以`real`类成员为实部和虚部的形式记录复数的值。其定义、初始化和使用方式同`double`类型相似，拥有许多处理复数的函数。

#### 二、数据成员

##### （一）公有



##### （二）私有



#### 三、函数

