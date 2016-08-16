#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    int numDecodings(string s) {
		if(s.empty()) return 0;
		int m = s.size();
		vector<int> dp(m+1,0);
		dp[0] = 1;
		for(int i=1;i<=m;i++)
		{
			if(s[i-1]=='0')
			{
				if(i==1 || (s[i-2]!='1'&&s[i-2]!='2'))
					return 0;
				else
					dp[i] = dp[i-2];
			}
			else if((s[i-2]=='1') || (s[i-2]=='2'&&s[i-1]<='6'&&s[i-1]>='0'))
				dp[i] = dp[i-1] + dp[i-2];
			else
				dp[i] = dp[i-1];
		}
		return dp[m];
    }
};

int main(){
	Solution sol;
	cout<<sol.numDecodings("1210")<<endl;
}
