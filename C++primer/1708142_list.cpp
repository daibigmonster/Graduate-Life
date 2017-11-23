#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>
void outint(int n){std::cout<<n<<" ";}
int main(){
    using namespace std;
    list<int> one(5,2);
    int stuff[5]={1,2,4,8,6};
    list<int> two;
    two.insert(two.begin(),stuff,stuff+5);
    int more[6]={6,4,2,4,6,5};
    
    list<int> three(two);
    three.insert(three.end(),more,more+6);
    
    cout<<"List one: ";
    for_each(one.begin(),one.end(),outint);
   
    cout<<endl<<"List two: ";
    for_each(two.begin(),two.end(),outint);
    
    cout<<endl<<"List three: ";
    for_each(three.begin(),three.end(),outint);
    
    three.remove(2);
    cout<<endl<<"List three minus 2s: ";
    for_each(three.begin(),three.end(),outint);
    
    three.splice(three.begin(),one);
    cout<<endl<<"List three after splice:";
    for_each(three.begin(),three.end(),outint);
    
    cout<<endl<<"List one: ";
    for_each(one.begin(),one.end(),outint);
    
    three.unique();
    cout<<endl<<"List three after unique: ";
    for_each(three.begin(),three.end(),outint);
    
    three.sort();
    three.unique();
    cout<<endl<<"List three after sort&unique: ";
    for_each(three.begin(),three.end(),outint);
    
    two.sort();
    three.merge(two);
    cout<<endl<<"Sort two merged int three: ";
    for_each(three.begin(),three.end(),outint);
    cout<<endl;
    
    return 0;
}
/*list工具箱
list方法组成了一个方便的工具箱，例如，假设由两个邮件列表要整理i，则可以对，则可以对每个列表进行排序，合并它们，然后使用unique()来删除重复的元素
queue模板的限制比deque更多。它不仅不允许随机访问队列元素，甚至不允许遍历队列。它把使用限制在定义队列的基本操作上，可以将元素添加到队尾、从队首删除元素、查看队首和队尾的值、检查元素数目和测试队列是否为空。
priority_queue
它支持的操作与queue相同，来嗯这的主要区别在于，在priority_queue中，最大的元素被移到队首。可以修改用于确定那个元素放到队首的比较方式。
priority_queue<int> pq1;
priority_queue<int> pq2(greater<int>);
stack
stack模板的限制比vector更多。它不允许随机反问栈元素，甚至不允许遍历栈。它把使用限制在定义栈的基本操作上，即可以将压入推到栈顶、从栈顶弹出元素、查看栈顶的值、检查元素数目和测试栈是否为空
与queue()相似，如果要使用栈中的值，必须首先使用top()来检索这个值，然后使用pop()将它从栈中删除
array
array没有调整容器大小的操作。可以将很多STL算法用于array对象，如copy()和for_each().


