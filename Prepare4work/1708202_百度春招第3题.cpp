#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>  
using namespace std;
struct point{
    char colour;
    double x,y,z;
};
double dist(point a,point b){
    return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2)+pow((a.z-b.z),2));
}
double area(point a,point b,point c){
     double x=dist(a,b);
     double y=dist(b,c);
     double z=dist(a,c);
     double s=(x+y+z)/2;
     return sqrt(s*(s-x)*(s-y)*(s-z));
}
bool Iscolour(point a,point b,point c){
     if((a.colour==b.colour&&b.colour==c.colour)||
         ((a.colour!=b.colour)&&(b.colour!=c.colour)&&(a.colour!=c.colour)))
         return true;
     else return false;
}
int main(){
    int n;
    double maxarea=0;
    cin>>n;
    point points[n];
    for(int i=0;i<n;i++)
        cin>>points[i].colour>>points[i].x>>points[i].y>>points[i].z;
    
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(Iscolour(points[i],points[j],points[k])){
                double temp=area(points[i],points[j],points[k]);
                if(temp>maxarea)maxarea=temp;
                }
            }
        }
    }
    printf("%.5f",maxarea);
    return 0;
}
