/*本章将介绍如何对类使用new和delete以及如何处理由于使用动态内存而引起的一些微妙的问题，它们将影响构造函数和析构函数的设计以及运算符的重载
 * 来看一个具体的例子——C++如何增加内存的负载，假设要创建一个类，其一个成员表示某人的姓。最简单的方法是使用字符数组来保存姓，但这种方法由一些缺陷。开始也许会使用一个14个字符的数组，然后发现数组太小，更保险的方法是，使用一个40个字符的数组。然而，如果创建包含2000个这种对象的数组，就会由于字符数组只有部分被使用而浪费大量的内存。
 * 通常最好是在程序运行时（而不是编译时）确定诸如使用多少内存等问题。对于在对象中保存姓名来说，通常的C++方法是，在类构造函数中使用new运算符在程序运行时分配所需的内存。为此，通常的方法是使用string类。除非同时执行一系列额外步骤，如扩展析构函数、使所有的构造函数与new析构协调一致、编写额外的类方法来帮助正确完成初始化和赋值，否咋，在类构造函数中使用new将导致新问题
 * 新的小程序：这个程序使用了一个新的存储类型：静态类成员。首先设计一个stringBad类，然后设计一个功能稍强的string类
 * StringBad和String类对象将包含一个字符串指针和一个表示字符串长度的值。这里使用stringBad和String类，主要是为了深入理解new、delete和静态类成员的工作原理。因此，构造函数和析构函数调用时将显示一些信息，以便您能够按照提示完成操作。另外，将省略一些有用的成员和友元函数，如重载的++和>>运算符以及转换函数，以简化类接口。
 */
#include <iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_ 
class StringBad{
private:
    char * str;
    int len;
    static int num_strings;//number of objects
public:
    StringBad(const char* s);
    StringBad();
    ~StringBad();
    friend std::ostream & operator<<(std::ostream & os,const StringBad & st);
};
#endif
