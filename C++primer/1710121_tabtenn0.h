//tabtenn0.h
//C++类提供了更高层次的重用行。目前，很多厂商提供了类库，类库由类声明和实现构成。因为类组合了数据表示和类方法，因此提供了比偶函数库更加完整的程序包。下面是可以通过类继承完成的一些工作。
//可以在已有类基础上添加功能。
//可以给类添加数据。
//可以修改方法的行为。
#ifndef TABTENN0_H_
#define TABTENN0_H_
#include <string>
using std::string;
class TableTennosPlayer
{
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    TeableTennisPlayer (
    const string & fn = "none",
    const string & ln = "none",bool ht = false
    );
    //需要有一种新的语法——保证函数不会修改调用对象。C++的解决方法是将const关键字放在函数括号的后面。
    //void show() const;
    //以这种方式声明和定义的类函数被称为const成员函数。
    void name() const;
    
    bool Hast
}
