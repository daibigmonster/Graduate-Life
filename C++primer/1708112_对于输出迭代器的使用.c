#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
int main()
{
   int cast[50]={6,7,2,3,1,2,3,1,2,3};
   vector<int> dice(10);
   copy(cast,cast+10,dice.begin());
   /*for(auto x:dice)
      cout<<x<<" ";
   cout<<endl;*/
   ostream_iterator<int,char> out_iter(cout," ");
   copy(dice.begin(),dice.end(),out_iter);
   cout<<"123134"<<endl;
   return 0;
}
