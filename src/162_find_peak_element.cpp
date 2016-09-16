#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		if(nums.empty()) return -1;
		int start = 0, end = nums.size()-1, mid = 0;
		if(nums.size()<3) return nums[start]>=nums[end]?start:end;

		while(start<=end){
			int mid = (start+end)>>1;
			if(mid==0){
				if(nums[mid+1]<nums[mid]){
					return mid;
				}
				else{
					start = mid+1;
				}
			}
			if(mid==nums.size()-1){
				if(nums[mid-1]<nums[mid]){
					return mid;
				}
				else{
					end = mid-1;
				}
			}
			else{
				if(nums[mid-1]<nums[mid] && nums[mid+1]<nums[mid])
					return mid;
				else if(nums[mid-1]>nums[mid+1])
					end = mid-1;
				else
					start = mid+1;
			}
		}
		return -1;
    }
};

int main(){
	int arr[] = {1,2,0,4};
	vector<int> vec(arr,arr+sizeof(arr)/sizeof(int));
	Solution sol;
	cout<<vec[sol.findPeakElement(vec)]<<endl;

}
