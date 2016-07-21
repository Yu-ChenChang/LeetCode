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
		backtracking(res,s,1,2,3);
		return res;
    }
private:
	void backtracking(vector<string>& res, string& s, int dot1Begin,int dot2Begin,int dot3Begin){
		string s1 = s.substr(0,dot1Begin);
		string s2 = s.substr(dot1Begin,dot2Begin-dot1Begin);
		string s3 = s.substr(dot2Begin,dot3Begin-dot2Begin);
		string s4 = s.substr(dot3Begin);
		if(atoi(s1.c_str())<256&&atoi(s2.c_str())<256&&atoi(s3.c_str())<256&&atoi(s4.c_str())<256&&(s1[0]!='0'||s1.length()==1)&&(s2[0]!='0'||s2.length()==1)&&(s3[0]!='0'||s3.length()==1)&&(s4[0]!='0'||s4.length()==1)) res.push_back(s1+"."+s2+"."+s3+"."+s4);
		dot3Begin++;
		if(dot3Begin>=s.length())
		{
			dot2Begin++;
			dot3Begin = dot2Begin+1;
		}
		if(dot2Begin>=s.length()-1)
		{
			dot1Begin++;
			dot2Begin=dot1Begin+1;
			dot3Begin=dot2Begin+1;
		}
		if(dot1Begin>=s.length()-2)
			return;

		backtracking(res,s,dot1Begin,dot2Begin,dot3Begin);
	}
};

int main(){
	Solution sol;
    vector<string> res = sol.restoreIpAddresses("123456");
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<endl;

}
