/*string类虽然不是STL的组成部分，但设计它时考虑到了STL。
下面的程序用STL显示了使用一个词的字母可以得到所有的排列组合。排列组合就是重新安排容器中元素的顺序。next_permutation()算法将区间内容转换为下一种排列方式。对于字符串，排列按转字母递增的顺序进行。如果成功，该算法返回true;如果区间已经处于最后的序列中，则该算法返回false.姚得到区间内容所有的排列组合，应从最初的顺序开始，为此程序使用了STL算法sort().*/
#include<iostream>
#include<string>
#include<algorithm>
int main(){
    using namespace std;
    string letters;
    cout<<"Enter the letter grounp (quit to qiut): ";
    while(cin>>letters&&letters!="quit"){
        cout<<"Permutations of "<<letters<<endl;
        sort(letters.begin(),letters.end());
        cout<<letters<<endl;
        while(next_permutation(letters.begin(),letters.end()))
            cout<<letters<<endl;
        cout<<"Enter next sequence (quit to quit): ";
    }
    cout<<"Bye.\n";
    return 0;
}
