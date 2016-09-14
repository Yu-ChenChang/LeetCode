#include<vector>
#include<string>
#include<iostream>
#include<utility>
using namespace::std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
		if(nums.empty()) return 0;
		int n=nums.size();
		int res = nums[0];
		vector<pair<int,int> > dp(n,pair<int,int>(0,0));
		dp[0].first = nums[0];
		dp[0].second = nums[0];
		for(int i=1;i<n;i++){
			dp[i].first = max(nums[i],max(dp[i-1].first*nums[i],dp[i-1].second*nums[i]));
			dp[i].second = min(nums[i],min(dp[i-1].first*nums[i],dp[i-1].second*nums[i]));
			res = max(res,dp[i].first);
		}
		return res;
    }
};

int main(){
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(2);
	Solution sol;
	cout<<sol.maxProduct(nums)<<endl;

}
