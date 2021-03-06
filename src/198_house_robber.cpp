#include<vector>
#include<string>
#include<iostream>
using namespace::std;
class Solution {
public:
	int rob(vector<int>& nums) {
		if(nums.empty()) return 0;
		int m = nums.size();
		vector<int> dp(m+1,0);			
		dp[0] = 0;
		dp[1] = nums[0];
		for(int i=2;i<=m;i++)
			dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]);

		return dp[m];
	}
};

int main(){

}
