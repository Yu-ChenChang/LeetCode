#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    int minCut(string s) {
		if(s.empty()) return 0;
		int n = s.size();
		vector<vector<bool> > isPal(n,vector<bool>(n,0));
		for(int i=0;i<n;i++)
			isPal[i][i] = 1;
		for(int i=1;i<n;i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				if((i-j<2 || isPal[j+1][i-1]) && s[j]==s[i])
					isPal[j][i] = 1;
			}
		}
		vector<int> dp(n+1,INT_MAX);
		dp[0] = -1;
		for(int i=1;i<=n;i++)
			for(int j=i;j>0;j--)
			{
				if(isPal[j-1][i-1])
					dp[i] = min(dp[i],dp[j-1]+1);
			}
		return dp[n];
    }
};

int main(){

}
