#include<iostream>
#include<vector>
using namespace std;
int main(){
    int x,f,d,p;
    while(cin>>x>>f>>d>>p){
        int days;
        if(d<=f*x)days=int(d/x);
        else days=int((d+f*p)/(x+p));
        cout<<days<<endl;
    }
    return 0;
}
