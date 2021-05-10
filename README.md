# 面向对象的科学计算库（OSL）

版权所有©2021 詹煜民，<https://github.com/YumiZhan>

### 其它语言

- [English](https://github.com/YumiZhan/OSL/blob/master/README_en.md) 



OSL 是基于 C++ 语言编写的用于解决科学计算问题的库。它使用面向对象的方式来构建更复杂的数学对象，从而简化数值方法求解的程序设计。OSL 是开源的，并且提供链接库和应用程序。OSL 遵循 GPL 3.0 许可，详见 [LICENSE](https://github.com/YumiZhan/OSL/blob/master/LICENSE/LICENSE.md)。



## 获取方式

OSL 已经开源发布到如下网站中

- [Github](https://github.com/YumiZhan/OSL) 
- [Gitee](https://gitee.com/YumiZhan/OSL) 

您可以下载代码文件或者下载发行的编译和头文件支持、软件等。一般来说，如果您只需要基于本项目进行拓展开发而无需更改代码，可以只下载发行版，里面包含了头文件、链接库、运行时文件和此文档。OSL 各子库的使用方式详见其 “使用方式” 标题下的内容。本项目依赖的额外资源及相关说明已经放到了 “Dependent package backup” 目录中以便使用。



## Number 库

### 使用方式

将 number.h 和 number.lib 放置到项目的同一个文件夹中，调用 rational 或 complex 类前包含头文件（如`#include "number.h"`）。运行程序前，把 number.dll 放置在可执行文件（如 example.exe）所在的文件夹里。



### 类型别名说明

- `agm_rtn`：数字类型`const rational&`的别名，一般用作 `rational` 类相关函数的参数类型
- `agm_cpl`：数字类型 `const complex&` 的别名，一般用作 `complex` 类相关函数的参数的类型



### rational 类

#### 一、简介

以`double`类型数值为分子和分母的分数形式记录数值，拥有已知性标识。由于使用分数的方式记录数值，在数值计算过程中，它有效地规避了计算机内存有限地储存无限循环小数造成的精度损失，因此其运算精度不低于`double`类型，理论上可以以足够大的精度表示任意有理数；然而由于利用了更多的函数重载，其定义、初始化和使用的方式却与`double`类型几乎完全相同。

#### 二、数据成员

##### (一) 私有

- `double _denominator`：分母
- `double _numerator`：分子
- `simplify()`：调用 `simplify_fraction()` 函数化简对象分数

##### (二) 公有

- `bool known`已知性标识

#### 三、函数

##### (一) 构造函数 (rational.cpp)

- 复制构造函数
- 含一个带默认值的 `double` 参数的构造函数（也作为默认构造函数）
- 两个`double`参数的构造函数，分别为分子和分母
- 使用 C 风格字符串来初始化
- 使用指向 `wchar_t` 类型的指针来初始化

##### (二) 功能函数 (rational.cpp)

- `zero()`：判断是否为零
- `infinite()`：判断是否无穷大
- `denominator()`：返回分母
- `numerator()`：返回分子
- `print()`：以 `double` 的形式打印，并输出一个回车
- `show()`：以 “分子 / 分母” 的形式打印，并输出一个回车
- `to_radian()`：将角度转换成弧度
- `to_degree()`：将弧度转换成角度

##### (三) 修改器 (rational_modifier.cpp.cpp)

- `rec()`：倒置
- `rabs()`：绝对值化
- `add()`：自增一个数
- `sub()`：自减一个数
- `mul()`：自乘一个数
- `div()`：自除一个数

##### (四) 比较 (rational_comparation.cpp)

- `larger_than()`：判断大于
- `not_less_than()`：判断不小于
- `less_than()`：判断小于
- `not_larger_than()`：判断不大于
- `equal_to()`：判断一定精度下的绝对相等

##### (五) 运算符重载 (rational_overload_operators.cpp)

以下内容省略`operator`符号

###### 1. 类型转换

- `double()`：返回 rational 对象的 double 值

###### 2. 流输出和读入

- `<<()`：流输出
- `>>()`：流读取

###### 3. 特殊处理

- `~()`：倒数

###### 4. 复合赋值

- `+=()`：加法复合赋值
- `-=()`：减法复合赋值
- `*=()`：乘法复合赋值
- `/=()`：除法复合赋值
- `^=()`：数函数复合指赋值

###### 5. 自增和自减运算

- `++()`：自增
- `--()`：自减

###### 6. 基本运算

- 单目 `+()`：返回原值
- 单目 `-()`：返回相反数
- 双目 `+()`：加法
- 双目 `-()`：减法
- `*()`：乘法
- `/()`：除法
- `^()`：指数函数

###### 7. 逻辑运算

- `==()`：相等
- `!=()`：不相等
- `<()`：小于
- `<=()`：小于等于
- `>()`：大于
- `>=()`：大于等于
- `!()`：是否未知

##### (六) `<cmath>`函数重载 (rational_overload_cmath.cpp)

参考：http://www.cppfans.com/cbknowledge/reference/cmath/

- `cos()`：余弦
- `cosh()`：双曲余弦
- `sin()`：正弦
- `sinh()`：双曲正弦
- `tan()`：正切
- `tanh()`：双曲正切
- `acos()`：反余弦
- `acosh()`：反双曲余弦
- `asin()`：反正弦
- `asinh()`：反双曲正弦
- `atan()`：反正切
- `atan2()`：双参数的反正切
- `atanh()`：反双曲正切
- `exp(x)`：计算 $e^x$
- `exp2(x)`：计算 $2^x$
- `expm1(x)`：计算 $e^x - 1$
- `frexp(num, *exponent)`：把`num`分解成有效数字和指数，返回有效数字，指数存入`exponent`中
- `ldexp(num, exponent)`：`num`乘以 2 的`exponent`次幂
- `log()`：取对数
- `ln()`：以 e 为底的对数
- `log2()`：以 2 为底的对数
- `log10()`：以 10 为底的对数
- `lg()`：同上
- `log1p(x)`：计算 $\ln(1+x)$
- `copysign(x, y)`：返回由 y 的符号和 x 的绝对值组成的数
- `modf(x, *integer)`：返回 x 的小数部分，整数部分存入`integer`
- `pow(x, y)`：返回 x 的 y 次幂
- `pow2()`：平方
- `pow10()`：10 次方
- `sqrt()`：平方根
- `hypot(x, y)`：计算 $\sqrt{x^2+y^2}$
- `ceil()`：向上取整
- `round()`：四舍五入取整
- `floor()`：向下取整
- `trunc()`：丢弃小数部分取整
- `fabs()`：绝对值
- `fmod(x, y)`：返回 x 除以 y 的余数



### complex 类

#### 一、简介

以`double`类成员为实部和虚部的形式记录复数的值。其定义、初始化和使用方式同`double`类型相似，拥有许多处理复数的函数。

#### 二、数据成员

##### (一) 私有

- `_real`：实部
- `_imag`：虚部

##### (二) 公有

- `known`：已知性标识

#### 三、函数

##### (一) 构造函数 (complex.cpp)

- 复制构造函数
- 一个带默认值的 `double` 参数的构造函数（同时作为默认构造函数）
- 两个 `double` 参数和一个模式标识的构造函数

##### (二) 功能函数 (complex.cpp)

###### 1. 控制台输出

- `console_print_rect()`：以  的形式输出到控制台
- `console_print_polar()`：以  的形式输出到控制台

###### 2. 属性

- `real()`：返回实部
- `imag()`：返回虚部
- `abs()`：返回绝对值
- `abs2()`：返回绝对值的平方
- `agl()`：返回角度
- `logabs()`：返回绝对值的自然对数

##### (三) 修改器 (complex_modifier.cpp)

- `add()`：自增一个复数
- `sub()`：自减一个复数
- `mul()`：自乘一个复数
- `div()`：自除一个复数
- `exc()`：交换实部和虚部
- `absc()`：将实部和虚部分别变为原来的绝对值

##### (四) 实用函数 (complex_unility_functions.cpp)

###### 1. 比较

- `equal_to()`：是否相等

###### 2. 复数基本运算

- `conjugate()`：返回共轭复数
- `inverse()`：返回倒数
- `pow()`：指数函数
- `sqrt()`：开方
- `exp()`：自然对数的底的指数函数
- `log()`：对数
- `ln()`：自然对数
- `log10()`：以 10 为底的对数
- `lg()`：同上

###### 3. 三角函数和反三角函数

- `cos()`：余弦
- `sin()`：正弦
- `tan()`：正切
- `csc()`：余割
- `sec()`：正割
- `cot()`：余切
- `acos()`：反余弦
- `asin()`：反正弦
- `atan()`：反正切
- `acsc()`：反余割
- `asec()`：反正割
- `acot()`：反余切

###### 4. 双曲函数和反双曲函数

- `cosh()`：双曲余弦
- `sinh()`：双曲正弦
- `tanh()`：双曲正切
- `csch()`：双曲余割
- `sech()`：双曲正割
- `coth()`：双曲余切
- `acosh()`：反双曲余弦
- `asinh()`：反双曲正弦
- `atanh()`：反双曲正切
- `acsch()`：反双曲余割
- `asech()`：反双曲正割
- `acoth()`：反双曲余切

##### (五) 运算符重载 (complex_overload_operators.cpp)

- `<<()`：流输出
- `>>()`：流读取
- `~()`：返回共轭复数
- 单目 `+()`：返回原值
- 单目 `-()`：返回相反数
- 双目 `+()`：加法
- 双目 `-()`：减法
- `*()`：乘法
- `/()`：除法
- `^()`：指数函数
- `+=()`：加法复合赋值
- `-=()`：减法复合赋值
- `*=()`：乘法复合赋值
- `/=()`：除法复合赋值
- `^=()`：指数函数复合指赋值
- `==()`：判断相等
- `!=()`：判断不相等



### 其它 (number.cpp)

- `simplify_fraction()`：将过大或过小的指数同时减小或增大一个相同的值，从而限制分子和分母的取值范围，使其不至于过大或过小
- `i`：`complex` 类对象，表示单位纯虚数



## Matrix 库

### 概要

#### 一、使用方式



#### 二、模板类的编译限制说明

编译器遇到模板时会在同一编译单元（如 .cpp 文件）的下文中搜索调用实例，若无相应类型的实例化调用，则不会为该类型生成定义代码；若在另一编译单元中调用了模板函数，则编译器进行连接时会查找对应类型的定义，若无定义则会导致连接失败。因此，对于 VC 和 GCC 等不支持 `export` 指令的编译器，只能将实例化和模板函数的定义放在同一编译单元中，如 element.cpp、vector.cpp 和 matrix .cpp。



### element 类

#### 一、简介

描述向量或矩阵中一个特定的元素的位置和属性值。

#### 二、数据成员

- `_row`：行号
- `_col`：列号
- `_value`：值

#### 三、函数

##### (一) 构造函数

- 默认构造函数
- 复制构造函数
- 用行号、列号和属性值来构造对象

##### (二) 功能函数

- `row()`：返回行号
- `col()`：返回列号
- `value()`：返回属性值



### vector 类

#### 一、简介

以动态分配一维数组为基础，`vector` 类是用于解决向量、有序数列或者行矩阵问题的模板类，支持以 `int`, `double` 和 Number 库中的类作为元素类型。

#### 二、数据成员（均为私有）

- `_size`: 向量的维数
- `point`: 指向数组的指针

#### 三、函数

##### (一) 构造函数

- `vector(int n, agm_elm value)`：构造有 n 个元素的向量，元素值均初始化为 `value`，所有参数都含默认值（同时作为默认构造函数）
- 复制构造函数
- `vector(agm_vct origin, int begin, int end)`：用 `origin` 的 `begin` 到 `end` 之间的元素来构造向量
- `vector(c_ary ary, int len)`：用 C 风格数组 ary 的前 len 个元素来构造向量

##### (二) 属性

- `empty()`：判断是否为空向量
- `size()`：返回向量维数

##### (三) 元素

- `at(int lct)`：返回第 lct 个元素的引用
- `MAX()`：返回值最大的元素的 `element` 对象
- `MIN()`：返回值最小的元素的 `element` 对象
- `absmax()`：返回绝对值最大的元素的 `element` 对象
- `absmin()`：返回绝对值最小的元素的 `element` 对象

##### (四) 修改器

- `cover()`：用一个值、一个 C 风格数组或者一个 vector 对象的一定元素来覆盖当前向量的元素
- `insert(int lct, ..)`：在 lct 位置插入指定数量的数、一个 C 风格数组或者一个 vector 对象
- `append()`：在末尾添加指定数量的数、一个 C 风格数组或者一个 vector 对象
- `remove()`：删除指定位置的元素
- `cutoff(int n)`：删除最后 n 个元素
- `add()`：按元素自增加
- `sub()`：按元素自减
- `mul()`：按元素自乘或总体自乘
- `div()`：按元素自除或总体自除

##### (五) 运算符重载

- `[]`：返回指定元素的引用
- `+`：向量相加
- `-`：向量相减
- `*`：向量点乘
- `<<`：将向量以 “[ x, y, z ]” 的形式插入到流中
- `>>`：从流中读取向量，用空格分开各元素

##### (六) 实用工具

- `print(c_str separator, char end)`：将向量流输出到控制台窗口中，`separator` 为分隔符，`end` 为输出最后添加的字符



### matrix 类

#### 一、简介

以动态分配的 `vector` 类数组为基础，`matrix` 类是用于解决矩阵问题的模板类，支持以 `int`, `double` 和 Number 库中的类作为元素类型。

#### 二、数据成员

- `_nrow`：行数
- `_ncol`：列数
- `pointer`：指向 `vector` 数组的指针

#### 三、函数

##### 1. 构造函数和析构函数

- `matrix(int nrow, int ncol, agm_elm value)`：构造一个 `nrow` 行 `ncol` 列的矩阵，元素值均初始化为 `value` 
- 复制构造函数
- `matrix(agm_mat origin, int start_row, int end_row, int start_col, int end_col)`：用 `origin` 的 `start_row` 至 `end_row` 行、`start_col` 至 `end_col` 列的元素来构造矩阵
- `matrix(agm_vec vec, int n)`：用 n 行 `vec` 来构造矩阵
- `matrix(c_ary ary, int ncol, int n)`：用 n 行 C 风格一维数组的前 `ncol` 列来构造矩阵
- `matrix(c_rary rary, int nrow, int ncol)`：用 C 风格二维数组的前 `nrow` 行和 `ncol` 列来构造矩阵

##### 2. 属性

- `empty()`：判断是否为空矩阵
- `nrow()`：返回矩阵行数
- `ncol()`：返回矩阵列数

##### 3. 元素

- `at(int row, int col)`：返回 `row` 行 `col` 列元素的引用
- `at(int row) const`：返回 `row` 行 `vector` 对象的备份
- `MAX()`：返回值最大的元素的 `element` 对象
- `MIN()`：返回值最小的元素的 `element` 对象
- `absmax()`：返回绝对值最大的元素的 `element` 对象
- `absmin()`：返回绝对值最小的元素的 `element` 对象

##### 4. 运算符重载

- `[](int row)`：返回第 `row` 行的备份



### 异常处理

#### 一、简介

不同于简单的数字运算，向量和矩阵的运算将涉及行和列的数量，需要谨慎对待：一是因为这些都对应着内存的地址，处理不当将会引发越界；二是规模不相称的向量和数组的运算是没有意义的。设计此异常接口将有利于编写异常处理程序，从而在发生异常时及时提醒用户。Matrix 库的异常类的定义在 exception.cpp 文件中。为了和 osl 命名空间中的 vector 类和 matrix 类区分，将它们的异常类定义于 osl 的子命名空间 exception 中。

#### 二、vector 类

##### 数据成员

- `code`：异常码
- `description`：描述异常发生位置或情况的 C 风格字符串
- `overview_list`：静态成员，包含一系列异常的概述

##### 函数

- `vector(unsigned code, c_str discription)`：用异常码和一个字符串来构造对象
- `overview()`：返回对应异常码的概述

#### 三、matrix 类

成员同上，只是 `overview_list` 的实际内容有差异。

