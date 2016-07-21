#include<iostream>
#include<vector>
#include<string.h>
using namespace::std;

class Solution {
public:
    void dfs(int ln,int rn,string s,int n,vector<string>& res){
        if(ln+rn == 2*n)
        {
            res.push_back(s);
            return;
        }
        if(ln<n)
            dfs(ln+1,rn,s+'(',n,res);
        if(rn<n&&rn<ln)
            dfs(ln,rn+1,s+')',n,res);
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(0,0,"",n,res);
        return res;
    }
};

int main(){
	Solution sol;
	int n=4;
	vector<string> res = sol.generateParenthesis(n);

	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j];
		cout<<endl;
	}
	return 0;
}
