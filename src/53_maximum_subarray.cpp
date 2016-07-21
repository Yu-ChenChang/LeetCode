#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int max = nums[0];
		int preSum = nums[0];
		if(nums.size()==1) return nums[0];
		for(int i=1;i<nums.size();i++)
		{
			if(preSum>0)
			{
				preSum += nums[i];
			}
			else
			{
				preSum = nums[i];
			}
			max = preSum>max?preSum:max;
		}
		return max;
	}
};

int main(){


}
