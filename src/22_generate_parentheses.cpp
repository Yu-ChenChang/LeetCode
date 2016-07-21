#include<iostream>
#include<vector>
#include<string.h>
using namespace::std;

class Solution {
public:
    void generate(vector<string>& res, string s, int leftN, int rightN, int level){
        if(leftN==rightN && rightN==level){
            res.push_back(s);
            return;
        }
        if(leftN<level)
        {
            generate(res,s+'(',leftN+1,rightN,level);
        }
        if(rightN<level && rightN<leftN)
        {
            generate(res,s+')',leftN,rightN+1,level);
            return;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res,"",0,0,n);
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
