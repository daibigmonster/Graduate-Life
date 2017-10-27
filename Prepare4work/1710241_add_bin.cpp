#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int sum = bin2dec(a) + bin2dec(b);
        return dec2bin(sum);
    }
    long long bin2dec(string a){
        long long anum = 0;
        if(!a.empty())
        {
            int length = a.size();
            for(int i = length - 1;i >= 0;i--)
            {
                if(a[i] == '1')anum += pow(2,length - 1 - i);
            }
            return anum;
        }
        return 0;
    }
    string dec2bin(long long sum)
    {
    		cout << sum << endl;
        if(sum == 0) return "0";
        string sumstr;
        while(sum)
        {
            int temp = sum % 2;
            sumstr.append(to_string(temp));
            sum = sum / 2;
        }
        return sumstr;
    }
};

int main(){
	string a,b,c;
	while(cin >> a >> b)
	{
		Solution s1;
		c = s1.addBinary(a,b);
		cout << c << endl;
	}
}
