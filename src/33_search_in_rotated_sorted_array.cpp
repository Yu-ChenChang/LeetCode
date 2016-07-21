#include<iostream>
#include<vector>
using namespace::std;


class Solution {
public:
	int binary_search(vector<int>& nums, int i, int j, int target){
		int size = j-i+1;
		int mid = i+size/2;
		bool flag;
		if(size<1)
			return -1;
		else if(size==1)
		{
			return target==nums[i]?i:-1;
		}
		else
		{
			if(target==nums[i]||target==nums[j])
				return target==nums[i]?i:j;
			if(target==nums[mid])
				return mid;
			else if(target<nums[mid])
			{
				if(nums[i]<nums[mid]&&target<nums[i])
					flag = false;
				else 
					flag = true;
			}
			else
			{
				if(nums[mid]<nums[j]&&target>nums[j])
					flag = true;
				else
					flag = false;
			}
			if(flag)
				return binary_search(nums,i,mid-1,target);
			else
				return binary_search(nums,mid+1,j,target);
		}
	}
    int search(vector<int>& nums, int target) {
		return binary_search(nums,0,nums.size()-1,target);
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
