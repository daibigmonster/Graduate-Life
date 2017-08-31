/*函数和容器方法
假设由一个由数字组成的链表，并要删除链表中某个特定值（例如4）的所有示例。如果la是list<int>对象，则可以使用链表的remove()方法
la.remove(4);
调用该方法后，链表中所有值为4的元素都将被删除，同时链表的长度将被自动调整。
还有一个名为remove()的STL算法，他不是由对象调用，而是接收区间参数。因此，如果lb是一个list<int>对象，则调用该函数的代码如下
remove(lb.begin(),lb.end(),4);
然而，由于该remove()函数不是成员，因此不能调整链表的长度。它将每被删除的元素放在链表的开始位置，并返回一个指向新的超尾值的迭代器。这样，便可以用该迭代器来修改容器的长度。例如，可以用链表的erase()方法来删除一个区间，该区间描述了链表中不再需要的部分。*/
#include<iostream>
#include<list>
#include<algorithm>
void Show(int);
const int LIM=10;
    using namespace std;
int main(){

    int ar[LIM]={4,5,4,2,2,3,4,8,1,4};
    list<int> la(ar,ar+LIM);
    list<int> lb(la);
    cout<<"Original list contents:\n\t";
    for_each(la.begin(),la.end(),Show);
    cout<<endl;
    la.remove(4);
    cout<<"After using the remove() method:\n";
    cout<<"la:\t";
    for_each(la.begin(),la.end(),Show);
    cout<<endl;
    auto last=remove(lb.begin(),lb.end(),4);
    cout<<"After using the remove() function:\n";
    cout<<"lb:\t";
    for_each(lb.begin(),lb.end(),Show);
    cout<<endl;
    lb.erase(last,lb.end());
    cout<<"After using the erase() method:\n";
    cout<<"lb:\t";
    for_each(lb.begin(),lb.end(),Show);
    cout<<endl;
    return 0;
}
void Show(int v){std::cout<<v<<' ';}
