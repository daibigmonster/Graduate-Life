#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<vector<int> > Alldayprices;
    vector<int> Singledayprice(3,0);
    int begindate,enddate,price;
    while(cin >> begindate >> enddate >> price){
        Singledayprice[0] = begindate;
        Singledayprice[1] = enddate;
        Singledayprice[2] = price;
        Alldayprices.push_back(Singledayprice);
    }
    int row = Alldayprices.size();
    int col = 3;
    vector<int> resarray(20000,0);
    for(int i = 0;i < row;i++){
        for(int j = Alldayprices[i][0];j <= Alldayprices[i][1];j++){
            resarray[j] = Alldayprices[i][2];
        }
    }

    int firstflag = 0;
    for(int i = 1;i < 20000;i++){
        if(resarray[i] != 0){
            begindate = i ;
            while(resarray[i] == resarray[i + 1])i++;
            enddate = i;
            price = resarray[i];
            if(!firstflag){
                cout << "[" << begindate << ", " << enddate << ", " << price << "]";
                firstflag++;
            }
            else{
                cout << "," << "[" << begindate << ", " << enddate << ", " << price << "]";}
        }
    }
    return 0;
}