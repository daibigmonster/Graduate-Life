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
auto pd=score.begin();
