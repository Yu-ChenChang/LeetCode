#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
		int begin = 0, end = nums.size()-1, mid;
		while(begin<=end)
		{
			mid = (begin+end)/2;
			if(target==nums[begin] || target==nums[mid] || target==nums[end]) return true;
			if(nums[begin]<=nums[mid])
			{
				if(nums[begin]==nums[mid]&&begin!=mid)
				{
					begin++;
					continue;
				}
				if(target>nums[begin]&&target<nums[mid]) end = mid-1;
				else begin = mid+1;
			}
			else if(nums[mid]<=nums[end])
			{
				if(target>nums[mid]&&target<nums[end]) begin = mid+1;
				else end = mid-1;
			}
		}
		return false;
    }
};

int main(){
	int arr[] = {1,1,0,1,1,1,2};
	vector<int> nums(arr,arr+sizeof(arr)/sizeof(int));
	Solution sol;
	cout<<sol.search(nums,0)<<endl;
}
