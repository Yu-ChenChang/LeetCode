#include<vector>
class Solution {
public:
	int removeElement(std::vector<int>& nums, int val) {
		if(nums.empty()) return 0;
		int pos = 0;
		
		for(int i=0;i<nums.size();i++)
		{
			if(nums[i]!=val)
			{
				int tmp = nums[i];
				nums[i] = nums[pos];
				nums[pos++] = tmp;
			}
		}
		return pos;
	}
};

int main(){

}
