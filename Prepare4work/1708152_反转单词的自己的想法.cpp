#include<iostream>
#include<string>
#include<vector>
#include<iterator>
using namespace std;
void Reverse(string &str,int begin,int end){
        if(begin<0||end<0)return;
        while(begin<end){
            char temp=str[begin];
            str[begin]=str[end];
            str[end]=temp;
            begin++,end--;
        }
    }
   string ReverseSentence(string str) {
        if(str.empty())return str;
        int begin=0;
        int end=str.size()-1;
        int length=str.size();
        Reverse(str,begin,end);
        begin=end=0;
        while(begin!=length){
            if(str[begin]==' ')
                begin++,end++;
            else if(str[end]==' '||end==length){
                Reverse(str,begin,--end);
                begin=++end;
            }
        /*    else if(end==string::npos){
               Reverse(str,begin,length-1);
            }*/
            else
                end++;
        }
        return str;
    }
int main()
{
    string temp;
    getline(cin,temp);
    cout<<ReverseSentence(temp)<<endl;
    return 0;
}
