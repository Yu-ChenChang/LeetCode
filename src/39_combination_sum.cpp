#include<iostream>
#include<vector>
#include<algorithm>
using namespace::std;

class Solution {
public:
     vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		sort(candidates.begin(),candidates.end());
		vector<vector<int> > res;
		vector<int> combinations;
		combinationSum(candidates,res,combinations,target,0);	
		return res;
    }
private:
	void combinationSum(vector<int> &candidates,vector<vector<int> >& res,vector<int>& combinations,int target,int begin){
		if(!target)
		{
			res.push_back(combinations);	
			return;
		}
		for(int i=begin;i!=candidates.size() && target>=candidates[i];i++)
		{
			combinations.push_back(candidates[i]);
			combinationSum(candidates,res,combinations,target-candidates[i],i);
			combinations.pop_back();
		}
	}
};

int main(){
	int array[4] = {2,3,6,7};
	int target = 7;
	vector<int> candidates(array,array+4);
	vector<vector<int> >res;
	Solution sol;
	res = sol.combinationSum(candidates,target);
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
