/*multimap示例
与set类似,multimap也是可反转的、经过排序的关联容器，但键和值的类型不同，且同一个键可能与多个值相关联。
基本的multimap声明使用模板参数指定键的类型和存储的值类型。例如下面的声明创建一个multimap对象，其中键类型为int,存储的值类型为string:
multimap<int,string> codes
第三个模板参数是可选的，指出用于对键进行排序的比较函数或对象。在默认情况下，将使用模板less<>,该模板将键类型作为参数。
为将信息结合在一起，实际的值类型将键类型和数据类型结合唯一对。为此，STL使用模板类pair<class T,class U>将这两种值存储到一个对象中，如果keytype是键类型，而datatype是存储的数据类型，而值类型为pai<const kettypt,datatype>.例如，前面声明的codes对象的值类型为pair<const int,string>.
例如，假设要用区号作为键来存储城市名（这恰好与codes声明一致，它将键类型声明为int,数据类型声明为string）,则一种方法是创建一个pair,再将它插入：
pair<const int,string> item(213,"Los Angeles");
codes.insert(item);
也可使用一条语句创建匿名pair对象并将它插入：
codes.insert(pair<const int,string>(213,"Losd Angeles"));
因为数据项是按键排序的，所以不需要指出插入位置。
对于pair对象， 可以使用first和second成员来访为其两个部分：
pair<sonst int,string> item(213,"Los Angeles");
cout<<item.first<<' '<<item.second<<endl;
如何获得有关multimap对象的信息呢？成员函数count()接收键作为参数，并返回该键的元素数目，成员行数lower_bounde()和upper_bound()将作为参数，且工作原理与处理set时相同，成员函数equal_range()用键作为参数，且返回两个迭代器，它们表示区间与该键匹配。为返回两个值，该方法将他呢把封装在一个pair对象中，这里pair的两个模板参数都是迭代器，例如，下面的代码打印codes对象中区号为718的所有城市
pair<multimap<KeyType,string>::iterator,multimap<KeyType,string>::
     iterator>range=codes.equal_range(718);
cout<<"Cities with area code 718:\n";
std::multimap<KeyType,std::string>::iterator it;
for(it=range.first;it!=range.second;++it)
    cout<<(*it).second<<endl;
在声明中可使用C++11自动类型判断功能，这样代码就可以简化为如下所示：
auto range=code.equal_range(718);
cout<<"Cities with area code 718:\n";
for(auto it=range.first;it!=range.second;it++)
    cout<<(*it).second<<endl;*/
#include<iostream>
#include<map>
#include<algorithm>
typedef int KeyType;
typedef std::pair<const KeyType,std::string> Pair;
typedef std::multimap<KeyType,std::string> MapCode;
int main()
{
    using namespace std;
    MapCode codes;
    codes.insert(Pair(415,"San Francisco"));
    codes.insert(Pair(510,"Oakland"));
    codes.insert(Pair(718,"Brooklyn"));
    codes.insert(Pair(718,"Staten Island"));
    codes.insert(Pair(415,"San Rafael"));
    codes.insert(Pair(510,"Berkeley"));
    cout<<"Number of cities with area code 415:"
    <<codes.count(415)<<endl;
    cout<<"Number of cities with area code 718:"
    <<codes.count(718)<<endl;
    cout<<"Number of cities with area code 510:"
    <<codes.count(510)<<endl;
    MapCode::iterator it;
    for(it=codes.begin();it!=codes.end();it++)
        cout<<" "<<(*it).first<<" "
            <<(*it).second<<endl;
    pair<MapCode::iterator,MapCode::iterator> range=codes.equal_range(718);
    cout<<"Cities With area code 718:\n";
    for(it=range.first;it!=range.second;++it)
        cout<<(*it).second<<endl;
    return 0;}
    /*无序关联容器
    无序关联容器是对容器概念的一种改进，与关联容器一样，无序关联容器也将值与键关联起来，并使用键来查找值，但底层的差别在于，关联容器是基于树结构的，而无序关联容器是基于数据结构哈希表的，值旨在提供添加和删除元素的速度以及提高查找算法的效率。*/
