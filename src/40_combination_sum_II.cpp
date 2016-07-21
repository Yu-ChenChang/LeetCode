#include<iostream>
#include<vector>
#include<algorithm>
using namespace::std;

class Solution {
public:
     vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
		sort(candidates.begin(),candidates.end());
		vector<vector<int> > res;
		vector<int> combinations;
		combinationSum2(candidates,res,combinations,target,0);	
		return res;
    }
private:
	void combinationSum2(vector<int> &candidates,vector<vector<int> >& res,vector<int>& combinations,int target,int begin){
		if(!target)
		{
			res.push_back(combinations);	
			return;
		}
		for(int i=begin;i!=candidates.size() && target>=candidates[i];i++)
		{
			if(i==begin || candidates[i]!=candidates[i-1])
			{
				combinations.push_back(candidates[i]);
				combinationSum2(candidates,res,combinations,target-candidates[i],i+1);
				combinations.pop_back();
			}
		}
	}
};

int main(){
	int array[4] = {2,5,6,7};
	int target = 7;
	vector<int> candidates(array,array+4);
	vector<vector<int> >res;
	Solution sol;
	res = sol.combinationSum2(candidates,target);
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
