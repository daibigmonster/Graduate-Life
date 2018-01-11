#include <iostream>
#include <vector>
using namespace std;
int getsum(int num,int n){
    int sum = 0;
    while(num){
        sum += num % n;
        num /= n;
    }
    return sum;
}
int measure(int x,int y){
    int z = y;
    while(x % y != 0){
        z = x % y;
        x = y;
        y = z;
    }
    return z;
}
int main(){
    int num,sum = 0;
    while(cin >> num){
        for(int i = 2;i < num;i ++) sum += getsum(num,i);
        int n = measure(sum,num - 2);
        cout << sum/n << "/" << (num - 2)/n << endl;
    }
    return 0;
}