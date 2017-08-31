/*为何使用迭代器
理解迭代器是理解STL的关键所在，模板使得算法独立于存储的数据类型，而迭代器是算法独立与使用的容器类型。
为了解为何需要迭代器，我们来看如何为两种不同数据表示实现find函数，然后看如何推广这种方法。首先看一个在double数组中搜索特定值的函数：
double* find(double *ar,int n,const double &val)
{
    for(int i=0;i<n;i++)
        if(ar[i]==val)
            return &ar[i];
    return 0;
}
如果函数在数组中找到这样的值，则返回该值在数组中的地址，否则返回一个空指针。该函数使用下标来遍历数组，可以用模板将这种算法推广到包含==运算符、任意类型的数组。尽管如此，这种算法仍然与一种特定的数据结构（数组）关联在一起。
下面看搜索另一种数据结构--链表的情况。链表由连接在一起的Node结构组成
struct Node
{
    double item;
    Node * p_next;
}
假设由一个指向链表第一个结点的指针，每个结点的p_next指针都指向下一个结点，链表最后一个结点的p_next指针被置为0,则可以这样编写find_ll()函数：
Node* find_ll(Node* head,const double& val)
{
    Node* start;
    for(start=head;start!=0;start=start->p_next)
        if(start->item==val)
            return start;
    return 0;
}
同样，也可以使用模板将这种算法推广到支持==运算符的任何数据类型的链表，然而，这种算法也是与特定的数据结构——链表关联在一起的。
从实现细节上来看，这两个find函数的算法是不哦嗯的，一个使用数组索引来遍历元素，另一个则将start重置为start->next。但从广义上来说，这两种算法是相同的。
泛型编程旨在使用同一个find函数来处理数组、链表或任何其他容器类型。即函数不仅独立于容器中存储的数据类型，而且独立与容器本身的数据结构。模板提供了存储在容器中的数据类型的通用表示，因此还需要遍历容器中的值的通用表示，迭代器正式这样的通用表示。
要实现find函数，迭代器应该具备那些特征呢？
1应能够对迭代器执行解除引用的操作，以便能够访问它引用的值，即如果p是一个迭代器，则应对*p进行对伊
2应能够将一个迭代器赋给另一个。即如果p和q都是迭代器，则应对表达式p=q进行定义
3应能够将一个迭代器与另一个进行比较，看他们是否相等。即如果p和q都是迭代器，则应对p==q和p!=q进行定义。
4应能够使用迭代器遍历容器中的所有元素，这可以为迭代器p定义++p和p++
迭代器也可以完成其他操作，但有上述功能就足够了,至少对于find函数是如此
重新编写find_arr()函数
typedef double* iterator;
iterator find_arr(iterator ar,int n,const double &val)
{
    for(int i=0;i<n;i++,ar++)
        if(*ar==val)
            return val;
    return 0;
 }
 按后尅修改函数参数，使之接受两个指示区间的指针参数，其中一个指向数组姿势位置，另一个指向数组的超尾;同时函数可以通过返回尾指针，来指出没有找到要找的值。下面find_ar()版本完成了这些修改：
 typedef double * iterator;
 iterator find_ar(iterator begin,iterator end,const double &val)
 {
     iterator ar;
     for(*ar==val)
         return ar;
     return end;
 }
 对于find_ll()函数，可以定义一个迭代器类，其中定义运算符*和++
 struct Node{
     double item;
     Node* p_next;
 }
 class iterator
 {
     Node* pt;
public:
    iterator():pt(0){};
    iterator(Node * pn):pt(pn){}
    double operator*()={return pt->item;}
    iterator& operator++()
    {
        pt=pt->p_next;
        return *this;
    }
    iterator operator++(int)
    {
        iterator tmp=*this;
        pt=pt->p_next;
        return tmp;
    }
}

有了这样的类后，第二个find函数就可以这样编写：
iterator find_ll(iterator head,const double &val)
{
    iterator start;
    for(start=head;start!=0;++start)
       if(*start==val)return start;
    return 0;
}
假设要打印vector<double>对象中的值，可以这样做：
vector<double>::iterator pr;
for(pr=scores.begin();pr!=scores.end();pr++)
    cout<<*pr<<endl;
使用C++11新增的自动类型推断可进一步简化，对于矢量或列表，都可使用如下代码：
for(auto pr=scores.begin();pr!=scores.end();pr++)
    cout<<*pr<<endl;
可以使用C++11新增的基于范围的for循环：
for(auto x:scores)cout<<x<<endl;
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    string ss;
    while(cin>>ss){
    for(auto x:ss)
        cout<<x<<endl;
    }
    return 0;
}
