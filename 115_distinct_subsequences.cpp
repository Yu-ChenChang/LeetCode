#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    int numDistinct_2d(string s, string t) {
        int** dp = new int*[t.size()+1];
        for(int i=0;i<=t.size();i++)
            dp[i] = new int[s.size()+1];
		for(int i=0;i<=t.size();i++)
			dp[i][0] = 0;
		for(int j=0;j<=s.size();j++)	
			dp[0][j] = 1;
		
        
        for(int i=0;i<t.size();i++)
        {
            for(int j=0;j<s.size();j++)
            {
				if(t[i]!=s[j])
					dp[i+1][j+1] = dp[i+1][j];
				else
					dp[i+1][j+1] = dp[i][j] + dp[i+1][j];
            }
        }
		return dp[t.size()][s.size()];
    }

    int numDistinct(string s, string t) {
		vector<int> dp(s.size()+1,1);
		for(int i=1;i<=t.size();i++)
		{
			int upLeft = dp[0];
			dp[0] = 0;
			for(int j=1;j<=s.size();j++)
			{
				int tmp = dp[j];
				dp[j] = dp[j-1];
				if(t[i-1]==s[j-1]) dp[j] += upLeft;
				upLeft = tmp;
			}
		}
		return dp[s.size()];
    }
};

int main(){

}
