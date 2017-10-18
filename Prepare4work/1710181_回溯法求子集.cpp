#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;


class Solution{
	vector<vector<int> >res;
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S)
	{
		if(S.empty()) return res;
		sort(S.begin(),S.end());
		vector<int> List;
		for(size_t i = 0;i <= S.size();i++)
			backtracking(S,i,0,List);
		sort(res.begin(),res.end());
		auto new_end = unique(res.begin(),res.end());
		res.erase(new_end,res.end());
		return res;

	}
	void backtracking(vector<int> S,int k,int start,
			vector<int> List){
		if(k < 0)return;
		if(k == 0)res.push_back(List);
		int length = S.size();
		for(int i = start;i <length;i++){
			List.push_back(S[i]);
			backtracking(S,k - 1,i + 1,List);
			List.erase(List.end() - 1);
		}
	}
};

int main()
{
	using namespace std;
	int num[3] = {1,2,2};
	vector<int> S;
	for(auto x:num) S.push_back(x);
	Solution Example;
	vector<vector<int> >res;
	res = Example.subsetsWithDup(S);
	for(auto x : res){
		for(auto y : x) cout<<y<<" ";
		cout<<endl;
	}
	return 0;
}
