#include<iostream>
#include<vector>
#include<algorithm>
using namespace::std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> >res;
        vector<int> combinations;
        combinationSum3(res,combinations,k,n,1);
        return res;
    }
    void combinationSum3(vector<vector<int> >& res,vector<int>& combinations,int k,int target,int begin){
        if(!target)
        {
            if(combinations.size()==k){
                res.push_back(combinations);
            }
        }
        for(int i=begin;i<10&&target-i>=0;i++)
        {
            combinations.push_back(i);
            combinationSum3(res,combinations,k,target-i,i+1);
            combinations.pop_back();
        }
	}
};

int main(){
	int target = 7;
	vector<vector<int> >res;
	Solution sol;
	res = sol.combinationSum3(3,target);
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
