#include <iostream>
using namespace std;
int get_ways(int x,int y){
    if(x == 0 && y == 0) return 0;
    if(x == 1 && y == 0) return 1;
    if(x == 0 && y == 1) return 1;
    if(x == 0) return get_ways(x,y - 1);
    if(y == 0) return get_ways(x - 1,y);
    return get_ways(x - 1,y) + get_ways(x, y - 1);
}
int main(){
    int m,n;
    while(cin>>m>>n)
        cout << get_ways(m,n) << endl;
    return 0;
}