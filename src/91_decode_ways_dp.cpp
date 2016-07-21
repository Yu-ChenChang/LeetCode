#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    int numDecodings(string s) {
		if(s.empty()||s[0]=='0') return 0;
		int* dp = new int[s.size()+1];
		
		dp[0]=1;
		dp[1]=1;
		for(int i=2;i<=s.size();i++)
		{
			if(s[i-1]=='0')
			{
				if(s[i-2]!='1'&&s[i-2]!='2') return 0;
				dp[i] = dp[i-2];
			}
			else if(s[i-2]=='1' || s[i-2]=='2'&&s[i-1]<='6')
				dp[i] = dp[i-1]+dp[i-2];
			else
				dp[i] = dp[i-1];
		}
		return dp[s.size()];
    }
};

int main(){
	Solution sol;
	cout<<sol.numDecodings("10")<<endl;
}
