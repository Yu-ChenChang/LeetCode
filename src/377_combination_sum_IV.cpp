#include<iostream>
#include<algorithm>
#include<vector>
using namespace::std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		int n = nums.size();
		vector<int> dp(target+1,0);
		dp[0] = 1;
		for(int i=0;i<=target;i++)
		{
			if(dp[i]==0) continue;
			for(int j=0;j<n;j++)
			{
				int t = i+nums[j];
				if(t<=target)
				{
					dp[t] += dp[i];
				}
			}
		}
		return dp[target];
	}
};

int main(){
	int arr[] = {4,2,1};
	int target = 32;
	vector<int> nums(arr,arr+sizeof(arr)/sizeof(int));
	Solution sol;
	cout<<sol.combinationSum4(nums,target)<<endl;
	

}
