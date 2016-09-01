#include<iostream>
#include<vector>

class Solution {
public:
	int removeDuplicates(std::vector<int>& nums) {
		if(nums.empty()) return 0;
		int end = 1;
		int curNum = nums[0];
		for(int i=1;i<nums.size();i++)
		{
			if(nums[i]>curNum)
			{
				curNum = nums[i];
				nums[i] = nums[end];
				nums[end++] = curNum;
			}
		}
		return end;
	}
};
int main(){

}
