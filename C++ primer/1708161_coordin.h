#ifndef COORDIN_H_
#define COORDIN_H_
struct polar{
    double distance;
    double angle;
};
struct rect{
    double x;
    double y;
};
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);
#endif
/*
在同一个文件中只能将同一个头文件包含一次。记住这个规则很容易，但很可能在不知情的情况下将头文件包含多次。例如，可能使用包含了另外一个头文件的头文件。下面的代码片段意味着仅当以前没有使用预处理器编译指令#define定义名称COORDIN_H_时，才处理#ifndef和#endif之间的语句：
#ifndef COORDIN_H_
...
#enddif
通常，使用#define语句来创建符号常量，如下所示：
#include MAXIMUN 4096
但只要将#define用于名称，就足以完成该名称的定义，如下所示
#define COORDIN_H_
程序9.1使用这种技术是为了将文件内容包含在#ifndef中
#ifndef COORDIN_H_
#define COORDIN_H_
#endif
编译器首次遇到该文件时，名称COORDIN_H_没有定义（我们根据include文件名来选择名称，并加上一些下划线，以创建一个在其他地方不太可能定义的名称）。在这种情况下，编译器将查看#ifndef和#endif之间的内容（这正是我们希望的），并读取COORDIN_H_的一行。如果在同一文件中遇到其他博阿含coordin.h的代码。编译器将直到COORDIN_H_已经被定义了，从而跳到#endif后面的一行上。*/
