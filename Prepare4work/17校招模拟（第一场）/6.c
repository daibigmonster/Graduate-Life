#include<iostream>
//#include<vector>
using namespace std;
int main()
{
    int sum,N;
    cin>>sum>>N;
    for(int i=N;i<=100;i++){
        if((2*sum+i-i*i)%(2*i)==0){
            int start=(2*sum+i-i*i)/(2*i);
            if(start>=0){
                for(int j=0;j<i-1;j++)
                    cout<<start+j<<" ";
                cout<<start+i-1<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
}
