//假设要生成一个随机的整数列表，并判断其中多少个整数可以被3整除，多少
//整数可以被13整除
//生成这样的列表可以用下面的方法
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
bool fthree(int x){return (x % 3 == 0);}
int randnum(){
	int count = rand()%100;
	return count;}

int main(){
	using std::cout;
	using std::endl;
	std::vector<int> numbers(20);
	std::generate(numbers.begin(),numbers.end(),randnum);
	int count = std::count_if(numbers.begin(),numbers.end(),fthree);
	for(auto x : numbers) cout << x << " ";
	cout << endl;
	cout << count << endl;
}
//通过使用算法count_if(),很容易计算出有多少个元素可以被3整除
