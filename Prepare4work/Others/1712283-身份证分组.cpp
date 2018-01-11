#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
        int index = 0;
        //去掉数组中所有的空格
        if(!s.empty())
        {
        	while( (index = s.find(' ',index)) != string::npos)
        	{
            	s.erase(index,1);
        	}
    	}
        int length = s.size();
        if(length <= 6) cout << s << endl;
        else if(length>6 && length<=14)
            cout << s.substr(0,6) << " " << s.substr(5) << endl;
        else
            cout << s.substr(0,6) << " " << s.substr(5) << " "
            << s.sub(13) << endl;
    }
} 
