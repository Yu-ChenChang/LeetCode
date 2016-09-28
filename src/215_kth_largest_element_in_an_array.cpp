#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums,0,nums.size()-1,k-1);
    }
    int quickselect(vector<int>& nums,int left,int right, int k){
        if(left==right) return nums[left];
        int pivot = nums[left];
        int i=left+1,j=right;
        while(i<=j){
            while(i<=j && nums[i]>=pivot) i++;
            while(i<=j && nums[j]<=pivot) j--;
            if(i<j) swap(nums[i],nums[j]);
        }
        swap(nums[left],nums[j]);
        if(j==k) return nums[j];
        else if(j<k) return quickselect(nums,j+1,right,k);
        else return quickselect(nums,left,j-1,k);
    }
};

int main(){
	vector<int> nums = {3,4,5,6,1,2,7};
	Solution sol;
	cout<<sol.findKthLargest(nums,2)<<endl;

}
