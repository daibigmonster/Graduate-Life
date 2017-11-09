/*对矢量可行性的其他操作
程序员通常要对数组执行很多操作，如搜索、排序、随机排序等。STl从更广泛的角度定义了非成员函数来执行这些操作，即不是为每个容器定义find()成员函数，而是定义了一个适用于所有容器类的非成员函数find().在定义新的容器类是，只要遵循正确的指导思想，它也可以使用已有的10个非成员函数来执行查找、排序等操作。
3个代表性的STL函数：for_eack()、random_shuffle()和sort().for_each()函数可用于很多容器类，它接受3个参数。前两个是定义容器中区间的迭代器，最后一个是指向函数的指针（更普遍地说，最后一个参数是一个函数对象）。for_each()函数将被指向的函数应用与容器区间中的各个元素。被指向的函数不能修改容器元素的值。可以用ofr_each()函数来代替for循环。例如，可以将代码：
vector<Review>::iterator pr
for(pr=books.begin();pr!=books.end();pr++)
    ShowReview(*pr);
替换为：
for_each(book.begin(),books.end(),ShowReview);
这样可避免显示第使用迭代器变量
Random_shuffle()函数接收来嗯个指定区间的迭代器参数，遍随机排列该区间中的元素。例如，下面的语句随机排列books矢量所有元素
random_shuffle(books.begin(),books.end())
与可用于任何容器类的for_each不同，该函数要求容器允许随机访问，vector可以做到这一点
sort()函数也要求容器支持随机访问。该函数由两本版本，第一个版本接收两个定义区间的迭代器参数，并使用为存储在容器中的类型元素定义的<运算符，对区间的元素进行操作。例如，下面的语句按升序对coolstuff的内容进行排序，排序时使用内置的<运算符对值进行比较
vector<int> coolstuff;
sor(coolstuff.befin(),coolstuff.end());
如果容器元素是用户定义的对象，若要使用sort(),必须定义能够处理该类型对象的operator<()函数。例如，如果为Review提供哦你了成员或非成员函数operator<(),则可以对包含Review对象的矢量进行排序。由于Review是一个结构，因此其成员是共有的，这样的成员函数将为：
bool operator<(const Review &r1,const Review &r2)
{
    if(r1.title<r2.title)return ture;
    else if(r1.title==r2.title&&r1.rating<r2.rating)return ture;
    else return false;
}
有了这样的函数后，就可以包含Review对象的十来嗯进行排序了
另一种格式的sor().它接受3个参数，前两个参数也是指定区间的迭代器，最后一个参数是只想要使用的函数的指针（函数对象）。返回值可转换为bool,false表示来两个参数的顺序不正确
bool WorseThan(const Review &r1,const Review &r2)
{
    if(r1.rating<r2.rating)return true;
    else return false;
}
有了这个函数之后，就可以使用下面的语句将包含Review对象的books矢量按rating升序排列*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Review{
    string title;
    int rating;
};
bool operator<(const Review &r1,const Review &r2);
bool worseThan(const Review &r1,const Review &r2);
bool FillReview(Review & rr);
void ShowReview(const Review &rr);
int main()
{   
    vector<Review> books;
    Review temp;
    while(FillReview(temp))
        books.push_back(temp);
    if(books.size())
    {
        cout<<"Thank you.You entered the following"
            <<books.size()<<" ratings:\n"
            <<"Rating\tBook\n";
        for_each(books.begin(),books.end(),ShowReview);
        
        sort(books.begin(),books.end());
        cout<<"Sorted by title:\nRating\tBook\n";
        for_each(books.begin(),books.end(),ShowReview);
        
        sort(books.begin(),books.end(),worseThan);
        cout<<"Sorted by rating:\nRating\tBook\n";
        for_each(books.begin(),books.end(),ShowReview);
        
        random_shuffle(books.begin(),books.end());
        cout<<"After shuffling:\nRating\tBook\n";
        for_each(books.begin(),books.end(),ShowReview);
    }
    else
        cout<<"No entries. ";
    cout<<"Bye.\n";
    return 0;
}
bool operator<(const Review &r1,const Review &r2)
{
    if(r1.title<r2.title)return true;
    else if(r1.title==r2.title&&r1.rating<r2.rating)return true;
    return false;
    }
bool worseThan(const Review &r1,const Review &r2){
    if(r1.rating<r2.rating)return true;
    else return false;
}
bool FillReview(Review &rr)
{   
    cout<<"Enter book title (quit to quit): ";
    getline(cin,rr.title);
    if(rr.title=="quit")return false;
    cout<<"Enter book rating: ";
    cin>>rr.rating;
    if(!cin)return false;
    while(cin.get()!='\n')continue;
    return true;
}
void ShowReview(const Review &rr)
{
    cout<<rr.rating<<"\t"<<rr.title<<endl;
}
/*基于范围的for循环
double prices[5]={4.99,10.99,6.87,7.99,8.49};
for(double x:prices)cout<<x<<endl;
for_each(books.begin(),books.end(),ShowReview);
可以替换为
for(auto x:books)ShowReview(x);
