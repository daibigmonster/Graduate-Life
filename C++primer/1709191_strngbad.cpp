/*将num_strings成员声明为静态存储类。静态类成员有一个特点：无论创建了多少对象，程序都只创建一个静态类便来嗯副本。也就是说，类的所有对象共享一个静态成员。这对于所有类对象都具有相同值的类私有数据是非常方便的。
 */
#include<cstring>
#include"1709181_strngbad.h"
using std::cout;
int StringBad::num_strings=0;

StringBad::StringBad(const char* s){
    len=std::strlen(s);
    str=new char[len+1];
    std::strcpy(str,s);
    num_strings++;
    cout<<num_strings<<":\""<<str
        <<"\" object created\n";
}
StringBad::StringBad(){
    len=4;
    str=new char[4];
    std::strcpy(str,"C++");
    num_strings++;
    cout<<num_strings<<":\""<<str
        <<"\" default object created\n";
}
StringBad::~StringBad(){
    cout<<"\""<<str<<"\" object deleted, ";
    --num_strings;
    cout<<num_strings<<" left\n";
    delete [] str;
}
std::ostream& operator<<(std::ostream & os,const StringBad & st){
    os<<st.str;
    return os;
}
/*int StringBad::num_strings=0;
 * 这条语句将静态成员num_strings的值初始化为0.请注意，不能在类声明中初始化静态成员变量，这是因为声明描述了如何分配内存，但并不分配内存。您可以使用这种格式来创建对象，从而分配和初始化内存。对于静态类成员，可以在类声明外使用单独的语句来进行初始化，这是因为静态类成员是单独存储的，而不是对象的组成部分。请注意，初始化语句指出了类型，并使用了作用域源算符，但没有使用关键字static.
 * 初始化是在方法文件中，而不是在类声明文件中进行的，这是因为类声明位于头文件中，程序可能将头文件包括在其他几个文件中。如果在头文件中进行初始化，将出现多个初始化语句副本，从而引发错误
 *对于不能在类声明中初始化静态数据成员是一种例外情况是，静态数据成员为整型或枚举型const
 */

