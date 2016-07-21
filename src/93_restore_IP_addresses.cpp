#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		int len = s.length();
		if(len>12 || len<4) return res;
		backtracking(res,"",s,0);
		return res;
    }
private:
	void backtracking(vector<string>& res,string cur, string s, int level){
		if(level==3)
		{
			int value = atoi(s.c_str());
			if(s.length()<1 || s[0]=='0'&&s.length()!=1 || value<0 || value>255) return;
			res.push_back(cur+s);
			return;
		}
		for(int i=1;i<4;i++)
		{
			if(s.length()<i) break;
			int value = atoi(s.substr(0,i).c_str());
			if(s[0]=='0'&&i>1 || value<0 || value>255) break;
			backtracking(res,cur+s.substr(0,i)+".",s.substr(i),level+1);
		}
	}
};

int main(){
	Solution sol;
    vector<string> res = sol.restoreIpAddresses("010010");
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<endl;

}
