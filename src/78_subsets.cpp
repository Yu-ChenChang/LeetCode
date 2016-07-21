#include<iostream>
#include<vector>
#include<algorithm>
using namespace::std;

class Solution {
public:
	void subsetOfK(int k,vector<int>& nums, vector<vector<int> >& res){
		vector<int> ans;
		int* pos = new int[k]();
		if(!k)
		{
			res.push_back(ans);
			return;
		}
		for(int i=0;i<k;i++)
		{
			pos[i] = i;
			ans.push_back(nums[pos[i]]);
		}
		res.push_back(ans);
		while(true)
		{
			for(int i=k-1;i>=0;i--)
			{
				if(pos[i]<nums.size()-1-(k-1-i))
				{
					ans.clear();
					pos[i]++;
					for(int j=i+1;j<k;j++)
						pos[j] = pos[j-1]+1;
					for(int j=0;j<k;j++)
						ans.push_back(nums[pos[j]]);
					res.push_back(ans);
					break;
				}
				else if(i==0) return;
			}
		}
	}

    vector<vector<int> > subsets(vector<int>& nums) {
		vector<vector<int> > res;
		if(nums.empty()) return res;
		sort(nums.begin(),nums.end());
		for(int i=0;i<=nums.size();i++)
		{
			subsetOfK(i,nums,res);
		}
		return res;
    }
};

int main(){
	Solution sol;
	int arr[] = {1,2,3};
	vector<int> nums(arr,arr+sizeof(arr)/sizeof(int));
	vector<vector<int> > res = sol.subsets(nums);	
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
}
