#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if(nums.empty()) return 0;
		if(nums.size()==1) return nums[0];
		int m = nums.size();
		vector<int> dp(m+1,0);
		vector<int> dpp(m+1,0);
		dp[0] = 0;
		dp[1] = nums[0];
		dpp[0] = 0;
		dpp[1] = 0;
		dpp[2] = nums[1];
		for(int i=2;i<=m;i++)
		{
			if(i!=2){
				dpp[i] = max(dpp[i-1],dpp[i-2]+nums[i-1]);
			}
			if(i!=m){
				dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]);
			}
		}
		return max(dp[m-1],dpp[m]);
	}
};

int main(){
	vector<int> nums(3,0);
	Solution sol;
	cout<<sol.rob(nums)<<endl;

}
