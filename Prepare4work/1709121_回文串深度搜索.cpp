void dfs(string s,vector<string>&path,vactor<vector<string> >&res){
	if(s.size()<1){
		res.pushback(path);
		return;
	}
	for(int i=0;i<s.size();i++){
		int begin=0;
		int end=i;
		while(begin<end){
			if(s[begin]==s[end]){
				begin++;
				end--;
			}
			else
				break;
		}
		if(begin>=end){
			path.push_back(s.substr(0,i+1))
			dfs(s.substr(i+1),path,res);
			path.pop_back();
		}
	}
}
vecotr<vector<string> >partition(string s){
	vector<vector<string> >res;
	vector<string>path;
	dfs(s,path,res);
	return res;
}
