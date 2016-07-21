#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        int left = 0;
        int right = nums.size()-1;
        //find left bound
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(nums[mid]<target)
                left = mid+1;
            else
                right = mid-1;
        }
        if(nums[right+1]==target)
            res[0] = right+1;
            
        //find right bound
        left = 0,right = nums.size()-1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(nums[mid]<=target)
                left = mid+1;
            else
                right = mid-1;
        }
        if(nums[left-1]==target)
            res[1] = left-1;
        return res;
    }
};

int main(){
	int array[] = {1};//{5,7,8,8,8,10};
	vector<int> data(array,array+1);
	int target = 0;
	Solution sol;
	vector<int> res = sol.searchRange(data,target);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
}
