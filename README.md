# Algorithm exercises
尘封已久的算法，又要重新开始刷题了，不知道题量能不能达到预期

研一寒假期间，断断续续的，平均下来大概每天一题，懒懒散散的，开学来了继续刷。

记录下让人眼前一新的算法题

喜欢就要勇敢去爱，对一件事，对一个人，如何付出，如何去追求，如何去爱，在付出的的过程中又如何去确定自己的内心？在追求一个目标或者一个人的时候，如何确保自己在付出的时候也是开心的？ \^_^

加油<(￣︶￣)↗[GO!]

## isPrime
判断质数，仅仅使用了sqrt，没有使用欧拉筛法、埃拉托斯特尼(Eratosthenes)筛法（记不住O(∩_∩)O哈哈~

## bigInt
大数的计算，重载运算符

## qpow
快速求幂的方法：递归的方式，时间复杂度是O(logn)

## bfs
广度优先搜索（广搜）：在图中找一条最短路径、扫雷

## dfs
深度优先搜索（递归，还可以dfs转bfs！

## rounding
将得到的百分数四舍五入。

利用int来保存最终结果，将得到的百分数+0.5：

1. 如果百分数小数位小于0.5，+0.5之后小数位小于1，int保留整数位，实现4舍

2. 如果百分数小数位大于0.5，+0.5之后小数位大于1，整数位+1，int再保留整数位，实现5入

## bigWhileTLE
一般的计算机每秒可执行约 10^8∼10^9 次运算，而 10^18 级别的循环需要的时间是不可接受的。
所以得控制好while循环的次数，如果次数太大，会超时。

## model
算法题模板，在solve函数中写题，rep、all、SZ、ll这些比较常用。

`ios::sync_with_stdio(0)`:

`std::ios::sync_with_stdio` 是一个静态成员函数，用于控制 C++ 标准输入输出流（`std::cin`、`std::cout` 等）与 C 标准输入输出流（`stdin`、`stdout` 等）的同步。当参数为 false（零值）时，会取消同步，这样可以提高 `std::cin` 和 `std::cout` 的读写速度。不过，取消同步后，就不能再混用 C 和 C++ 的输入输出函数了。

`if (is_file) {freopen("xxx.in","r",stdin); freopen("xxx.out","w",stdout);}`:

重定向输入和输出，输入从`xxx.in`文件读取，输出到`xxx.out`文件。

## dp
动态规划，换硬币哦