#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cmath>
using namespace std;
struct Point{
	int x,y;};
class Solution {
    string angle(Point a,Point b){
        if(a.x==b.x){
            if(a.y==b.y)return "somenode";
            else return "vetical";}
        else{
			double x=a.x-b.x;
			double y=a.y-b.y;
			double k=y/x;
       		if(abs(k-0)<1e-10)k=0;
			cout<<x<<" "<<y<<" "<<k<<" ";
        return to_string(int(k*1000000+0.5)/1000000.0);}}
public:
    int maxPoints(vector<Point> &points) {
        if(points.empty())return 0;
        int length=points.size(),maxcount=1;
        for(int i=0;i<length-1;i++){
            map<string,int>info;
            int samenode=0,vetical=0,curmax=1;
			cout<<i<<endl;
            for(int j=i+1;j<length;j++){
				cout<<j<<",";
                string ang=angle(points[i],points[j]);
                if(ang=="somenode")samenode++;
                else{
                    if(info[ang]==0)info[ang]=2;
                	else info[ang]++;
                    curmax=max(curmax,info[ang]);
			//		cout<<ang<<" "<<info[ang]<<" ";
				}
            }
			cout<<endl;
            maxcount=max(curmax+samenode,maxcount);
        }
        return maxcount;
    }
};
int main(){
	vector<Point> points;
	int x,y;
	while(cin>>x>>y){
		Point temp;
		temp.x=x;
		temp.y=y;
		points.push_back(temp);
	}
	Solution we;
	int res=we.maxPoints(points);
	cout<<res<<endl;
	return 0;
}
