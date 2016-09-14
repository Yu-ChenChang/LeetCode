#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    int findMin(vector<int>& nums) {
		return find(nums,0,nums.size()-1);
    }
private:
	int find(vector<int>& nums, int left, int right){
		int mid = (left+right)>>1;
		if(right-left<2){
			return min(nums[left],nums[right]);
		}
		if(nums[right]<nums[mid]){
			return find(nums,mid,right);
		}
		else if(nums[left]==nums[mid] && nums[mid]==nums[right]){
			return min(find(nums,left,mid),find(nums,mid,right));
		}
		else{
			return find(nums,left,mid);
		}
	}
};

int main(){

}
