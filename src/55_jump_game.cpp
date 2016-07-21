#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
		int index =0;
		int maxB = 0;
		int maxP = 0;
		while(index<nums.size())
		{
			maxP = index;
			if(nums[index]+index>=nums.size()-1) return true;
			for(int i=1;i<=nums[index];i++)
			{
				if(index+i+nums[index+i]>maxB)
				{
					maxB = index+i+nums[index+i];
					maxP = index+i;
				}
			}
			if(maxP==index)
				return false;
			index = maxP;
				
		}
		return true;
    }
};

int main(){

	int arr[] = {3,0,1,1,1,0,4};
	vector<int> vec(arr,arr+sizeof(arr)/sizeof(int));
	Solution sol;
	cout<<sol.canJump(vec)<<endl;
}
