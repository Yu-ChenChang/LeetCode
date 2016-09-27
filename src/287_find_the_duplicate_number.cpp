#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
		int n = nums.size();
		int left=1,right=n-1;
		while(left<right){
			int mid = (left+right)>>1;
			int sum = 0;
			for(int i=0;i<n;i++){
				if(nums[i]>=left && nums[i]<=mid) sum++;
			}
			if(sum<=mid-left+1) left = mid+1;
			else right = mid;
		}
		return left;
    }
};

int main(){

}
