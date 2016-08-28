#include<iostream>
#include<vector>

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if(nums.empty()) return 0;
		int pos = 1;
		int curNum = nums[0];
		for(int i=1;i<nums.size();i++)
		{
			if(nums[i]>curNum)
			{
				curNum = nums[i];
				nums[i] = nums[pos];
				nums[pos++] = curNum;
			}
		}
		return pos;
	}
};
int main(){

}
