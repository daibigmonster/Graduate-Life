// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <stdlib.h>
// using namespace std;
// int main(){
//     vector<int> num(10005,0);
//     int n,count = 6;
//     long long sum = 0;
//     for(int i = 1;i < 9998;i++){
//         cin >> n;
//         num[n] = n;
//     }
//     for(int i = 1;i < 10001;i++){
//         if(count == -3) break;
//         if(num[i] == 0){ 
//             sum += i * pow(10,count);
//             count -= 3;
//         }
//     }
//     cout << sum % 7 << endl;
// }
#include<stdio.h>
#include<string>
#include<sstream>
using namespace std;
int book[10005];
int main(){
    int x,i;
    for(i=0;i<9997;i++){
        scanf("%d",&x);
        book[x]=1;
    }
    long long sum=0;
    string res="",s;
    for(i=1;i<=10000;i++)
        if(book[i]==0){
            stringstream ss;
            ss<<i,ss>>s;
            res+=s;
        }
    stringstream ss(res);
    ss>>sum;
    printf("%d\n",sum%7);
}