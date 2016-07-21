#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if(nums.empty()) return 0;
		int fill=1;
		int count=1;
		for(int i=1;i<nums.size();i++)
		{
			if(nums[i]==nums[fill-1])
			{
				if(count==2)
					continue;
				nums[fill++] = nums[i];
				count++;
			}
			else
			{
				nums[fill++] = nums[i];
				count=1;
			}
		}
		return fill;
    }
};

int main(){
	int arr[] = {1,1,1,2,2,2,3};
	vector<int> nums(arr,arr+sizeof(arr)/sizeof(int));
	Solution sol;
	cout<<sol.removeDuplicates(nums)<<endl;
	for(int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;
}
