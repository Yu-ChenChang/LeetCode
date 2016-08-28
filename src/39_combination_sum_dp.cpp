#include<iostream>
#include<vector>
#include<algorithm>
using namespace::std;

class Solution {
public:
     vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		 vector<vector<vector<int> > > dp(target+1,vector<vector<int> >());
		 for(int i=0;i<candidates.size();i++)
		 {
			 vector<int> tmp(1,candidates[i]);
			 dp[candidates[i]].push_back(tmp);
		 }
		 for(int num=0;num<target+1;num++)
		 {
			 if(!dp[num].empty())
			 {
				 for(int i=0;i<candidates.size();i++)
				 {
					 int curNum = num+candidates[i];
					 if(curNum<target+1)
					 {
						 for(int vidx=0;vidx<dp[num].size();vidx++)
						 {
							 if(dp[num][vidx].back()<=candidates[i])
							 {
								 vector<int> one = dp[num][vidx];
								 one.push_back(candidates[i]);
								 dp[curNum].push_back(one);
							 }
						 }
					 }
				 }
			 }
		 }
		 return dp[target];
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
