#include<iostream>
#include<string>
#include<vector>
const int NUM=5;
using namespace std;
int main(){ 
    vector<int> ratings(NUM);
    vector<string> titles(NUM);
    cout<<"You will do exactly as told.You will enter\n"
    <<NUM<<" book titles and your ratings(0-10).\n";
    int i;
    for(int i=0;i<NUM;i++)
    {
        cout<<"Enter title #"<<i+1<<": ";
        getline(cin,titles[i]);
        cout<<"Enter your ratings(0-10): ";
        cin>>ratings[i];
        cin.get();
     }
     cout<<"Thank you:you entered the following:\n"
         <<"Rating\tBook\n";
     for(i=0;i<NUM;++i)
         cout<<ratings[i]<<"\t"<<titles[i]<<endl;
     return 0;
}
/*除了分配存储空间外，vector模板还可以完成那些任务呢？所有STL容器都提供了一些基本方法，其中包括size()
swap()---交换两个容器的内容、begin()、end()
C++11自动类型推断，比如，可以这样
vecotr<double>::iterator pd=score.begin();
可以这样：
auto pd=score.begin();
回到前面的示例，什么是超过结尾？它是一种迭代器，指向容器最后一个元素后面的那个元素。
erase()方法删除矢量中给定区间的元素。它接收两个迭代器参数，这些参数定义了要删除的空间。了解STL如何使用两个迭代器来定义区间只管重要。第一个迭代器指向区间的起始处，第二个迭代器位于区间中指出的后一个位置。例如，下述代码删除第一个和第二个元素，即删除begin()和begin()+1指向的元素（由于vector提供了随机访问功能，因此vector类迭代器定义了诸如begin()+2等操作）：
score.erase(scores.begin(),scores.begin()+2);
如果it1和it2是迭代器，则STL文档用[p1,p2)来表示从p1到p2(不包括p2)的区间。
insert()方法的功能与erase()相反它接收3个迭代器参数，第一个参数制定了新元素的插入位置，一二个和第三个迭代器参数定义了被插入区间，该区间通常是另一个容器对象的一部分。例如，下面的代码将矢量new_v中出第一个元素外的所有元素插入到old_v矢量的第一个元素前面：
vector<int> old_v;
vector<int> new_v;
顺便说一个，对于这种情况，拥有超尾元素是非常方便的，因为这使得在矢量尾部附加元素非常简单。下面的代码将新元素插入到old.end()前面
old_v.insert(old_v.end(),new_v.begin()+1,new_v.end())

