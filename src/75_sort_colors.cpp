#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
		if(nums.empty()) return;
		int n = nums.size();
		int red = 0;
		int blue = n-1;
		for(int i=0;i<blue+1;)
		{
			if(nums[i]==0) swap(nums[i++],nums[red++]);
			else if(nums[i]==2) swap(nums[i],nums[blue--]);
			else i++;
		}
		return;
    }
};

int main(){



}
