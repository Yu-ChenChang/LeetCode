#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace::std;

class Solution {
public:
	void nextPermutation(vector<int>& nums){
		for(int i=nums.size()-2;i>=0;i--)
		{
			if(nums[i]<nums[i+1])
			{
				for(int j=nums.size()-1;j>i;j--)
				{
					if(nums[j]>nums[i])
					{
						swap(nums[i],nums[j]);
						break;
					}
				}
				sort(nums.begin()+i+1,nums.end());
				return;
			}
		}
		sort(nums.begin(),nums.end());
		return;
	}
    vector<vector<int> > permuteUnique(vector<int>& nums) {
		vector<vector<int> > res;
		unordered_map<int,int> unmap;
		int total = nums.size();
		int tmp = nums.size()-1;
		//calculate for n!
		while(tmp>0)
		{
			total *= tmp--;
		}

		for(int i=0;i<nums.size();i++)
		{
			unmap[nums[i]]++;
		}
		for(unordered_map<int,int>::iterator it = unmap.begin(); it!=unmap.end();it++)
		{
			//remove repeated n!
			while(it->second >1){
				total/= (it->second)--;
			}
		}
		//permutation
       	for(int i=0;i<total;i++)
		{
			res.push_back(nums);
			nextPermutation(nums);
		}
		return res;
    }
};


int main(){
	int arr[] = {3,3,0,3};
	vector<int> nums(arr,arr+sizeof(arr)/sizeof(int));
	Solution sol;
	vector<vector<int> > res = sol.permuteUnique(nums);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
		{
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
