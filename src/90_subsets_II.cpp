#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace::std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
		vector<vector<int> > res;
		vector<int> cur;
		res.push_back(cur);
		if(nums.empty()) return res;
		sort(nums.begin(),nums.end());
		for(int i=1;i<=nums.size();i++)
			subsetsWithDup(0,0,i,nums,cur,res);
		return res;
    }
private:
	void subsetsWithDup(int index, int k, int n, vector<int>& nums, vector<int>& cur, vector<vector<int> >& res){
		if(k==n)
		{
			res.push_back(cur);
			return;
		}
		
		for(int i=index;i<nums.size();)
		{
			cur.push_back(nums[i]);
			subsetsWithDup(i+1,k+1,n,nums,cur,res);
			cur.pop_back();
			while(nums[i++]==nums[i]);
		}
	}
};

int main(){
	int arr[] = {1,1,2};
	vector<int> nums(arr,arr+sizeof(arr)/sizeof(int));
	Solution sol;
	vector<vector<int> >res = sol.subsetsWithDup(nums);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
}
