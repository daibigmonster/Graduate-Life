/*为何有三种智能指针呢，实际上由四种但本书不讨论weak_ptr.
为何摒弃auto_ptr呢？
先来看下面的赋值语句：
auto_ptr<string> ps (new string("I reigned lonely as a cloud."));
auto_ptr<string> vovation;
vocation=ps;
上面的赋值语句将完成什么工作呢？如果ps和vocation是常规指针，则两个指针将指向同一个string对象。这是不能接受的，因为程序将试图删除同一个对象两次——一次是ps过期时，另一次是vocation过期时。要避免这种问题，方法由多种。
定义赋值源算符，使之执行深复制。这样两个指针将指向不同的对象，其中一个对象是另一个对象的副本。
建立所有权概念，对于特定的对象，只有有一个智能指针可拥有它，这样只有拥有对象的智能指针的构造函数会删除该对象。然后让赋值操作转让所有权。这就是用于auto_ptr和unique_ptr的策略，但unique_ptr的策略更严格
创建智能更高的指针每，跟踪引用特定对象的只能指针树。这称为引用计数。例如赋值时，技术将加1,而指针过期时，技术将减1.进党最后一个指针过期时，采用delete.这是shared_ptr采用的策略*/
#include<iostream>
#include<string>
#include<memory>
int main(){
    using namespace std;
    auto_ptr<string> films[5]=
    {
        auto_ptr<string> (new string("Fowl Balls")),
        auto_ptr<string> (new string("Duck Walks")),
        auto_ptr<string> (new string("Chicken Runs")),
        auto_ptr<string> (new string("Turkey Errors")),
        auto_ptr<string> (new string("Goose Eggs")),
    };
    auto_ptr<string> pwin;
    pwin=film[2];
    cout<<"The nominees for best avian baseball file are\n";
    for(int i=0;i<5;i++){
        cout<<*films[i]<<endl;
    cout<<"The winnner is "<<*pwin<<"!\n";
    cin.get();
    return 0;
 }
 /*结果显示，错误地使用auto_ptr可能导致问题。这里的问题在于下面的于将将所有权从film[2]转让给pwin:
 这导致fils[2]不再引用该字符串。在auto_ptr放弃对象的所有权之后，遍可能使用它来访问该对象。当程序打印film[2]指向字符串时，却发现这是agiel空指针，这显然是错误。
如果在程序中使用sharedd_ptr代替auto_ptr，程序将正常运行
using namespace std;
unique_ptr<string > pu1(new string"Hi ho!");
unique_ptr<string> pu2;
pu2=pu1----->这是不允许的
unique_ptr<string> pu3;
pu3=unique<string>{new string "Yo!"};----->允许
语句#1将泪下悬挂的unique_ptr(pu1),这可能导致危害。语句#2不会留下悬挂的unique_ptr,因为它调用unique_ptr的构造函数，该构造函数创建的临时对象在其所有权转让给pu后就会被销毁，这种随情况而异的行为表明，unique_ptr由于允许两种赋值的auto_ptr
16.2.4选择智能指针
unique_ptr<int> make_int(int n)
{
    return unique_ptr(new int(n));
}
void show(unique_ptr<int> &pi)
{
    cout<<*a<<' ';
}
int main(){
....
    vector<unique_ptr<int> > vp(size);
    for(int i=0;i<vp.size();i++)
        vp[i]=make_int(rand()%1000);
    vp.push_back(make_int(rand()%1000));
    for_each(vp.begin,vp.end(),show);
.....}
 
