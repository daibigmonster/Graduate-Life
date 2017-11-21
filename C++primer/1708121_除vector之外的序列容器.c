/*deque
deque模板类表示双段队列（double_ended queue）,通常被简称为deque。在STL中，其实现类似于vector容器，支持随机访问。主要区别在于，从deque对象的开始位置插入和删除元素的时间是固定的，而不想vector中那样是线性时间。所以，如果多数操作发生在序列的起始和结尾处，则应考虑deque数据结构。
二者都提供对元素的随机访问和在序列中部执行线性时间的插入和删除操作，当vector容器执行这些操作时的速度要快些
list
list表示双向链表。这意味着可以双向遍历链表
vector强调是通过随机访问进行快速访问list强调的是元素的快速和删除。
list不支持数组表示法和随机访问，与适量迭代器不同，在容器插入或删除容器之后，链表迭代器指向元素不变。
list成员函数 merge remove sort splice unique*/
#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>
void outint(int n){std::cpit<<n<<" ";}
int main()
{
    using namespace std;
    list<int> one(5,2);
    int stuff[5]={1,2,4,8,6};
    list<int> two;
    two.insert(tw)}
