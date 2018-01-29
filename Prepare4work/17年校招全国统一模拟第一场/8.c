#include<iostream>
#include<cmath>
using namespace std;
int function(int A,int B,int K){
    int reminder=A%K;//反转之后待反转的个数
    int count=A/K;//反转次数
    int S=A+B;//总个数
    if(A==0|reminder==0);
    else if((S<=K)||(reminder%2==1&&K%2==0))return -1;//
    else if((K+reminder)%2==0
        &&count>0&&B+K*count>=2*K-(reminder+K)/2)count++;
    else if (reminder % 2 == 0)
        count += 2 * ceil(reminder/double(2 * (S - K)));
    else
        count += 2 * ceil((K - reminder) / double(2 * (S - K))) + 1;
    return count;
}
int main()
{
    int A, B, K;
    cin >> A >> B >> K;
    cout << function(A, B, K);
    return 0;
}
