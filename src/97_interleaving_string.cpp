#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		if(s3.size()!=s1.size()+s2.size()) return false;
		//dp[i][j] represents whether i length of s1 and j length of s2 is interleave of i+j length of s3
		bool dp[1000][1000] = {false};

		dp[0][0] = 1;
		for(int i=1;i<=s1.size();i++)
			dp[i][0] = dp[i-1][0] && s1[i-1]==s3[i-1];
		for(int j=1;j<=s2.size();j++)
			dp[0][j] = dp[0][j-1] && s2[j-1]==s3[j-1];

		for(int i=1;i<=s1.size();i++)
			for(int j=1;j<=s2.size();j++)
				dp[i][j] = dp[i-1][j]&&s1[i-1]==s3[i+j-1] || dp[i][j-1]&&s2[j-1]==s3[i+j-1];


		return dp[s1.size()][s2.size()];
    }
};

int main(){
	Solution sol;
	string s1="aaba";
	string s2="dbcc";
	string s3="aadbbaac";
	cout<<sol.isInterleave(s1,s2,s3)<<endl;
}
