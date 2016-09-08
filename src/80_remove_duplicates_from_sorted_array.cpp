#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int n = nums.size();        
		if(n<3) return n;
		int end = 2;
		for(int i=2;i<n;i++)
		{
			if(nums[i]!=nums[end-2])
			{
				swap(nums[i],nums[end++]);
			}
		}
		return end;
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
