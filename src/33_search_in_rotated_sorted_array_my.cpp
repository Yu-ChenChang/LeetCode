#include<iostream>
#include<vector>
using namespace::std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(0,nums.size(),nums,target);
    }
    int search(int begin,int size,vector<int>& nums,int target)
    {
        if(size<=0) return -1;
        int mid = begin+(size-1)/2;
        int tail = begin+size-1;
        
        if(target==nums[mid]) return mid;
        if(nums[mid]<nums[tail])
        {
            if(target>nums[mid] && target<=nums[tail])
                return search(mid+1,tail-mid,nums,target);
            else
                return search(begin,mid-begin,nums,target);    
        }
        if(nums[begin]<=nums[mid])
        {
            if(target>=nums[begin] && target<nums[mid])
                return search(begin,mid-begin,nums,target);    
            else
                return search(mid+1,tail-mid,nums,target);
        }
        return -1;
    }
};

int main(){
	int array[] ={7,8,1,2,3,4,5,6};//{4,5,6,7,0,1,2};
	vector<int> data(array,array+8);
	int target = 2;
	cout<<"target: "<<target<<endl;
	for(int i=0;i<data.size();i++){
		cout<<data[i]<<" ";
	}
	cout<<endl;
	Solution s1;
	cout<<s1.search(data,target)<<endl;
}
