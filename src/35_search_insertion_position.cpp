#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		int size = nums.size();
       	int left = 0;
		int right = size-1;
		int mid = size/2;

		while(left<right)
		{
			if(nums[mid]==target) return mid;
			else if(nums[mid]>target)
			{
				right = mid-1;
			}
			else
			{
				left = mid+1;
			}
			mid = left+(right-left+1)/2;
		}
		if(right==left && nums[mid]<target) return left+1;
		else return left;
    }
};

int main(){
	Solution sol;
	int arr[] = {3,4,6,8,10};//{1,2,4,5};
	vector<int> nums(arr,arr+5);
	int target = 11;
	cout<<sol.searchInsert(nums,target)<<endl;


}
