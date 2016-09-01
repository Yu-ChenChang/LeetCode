#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
		int n = s.size();
		vector<vector<bool> > isPal(n,vector<bool>(n,0));
		for(int i=0;i<n;i++)
			isPal[i][i] = 1;
		for(int i=1;i<n;i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				if((j+1>i-1||isPal[j+1][i-1]) && s[j]==s[i])
				{
					isPal[j][i] = 1;
				}
			}
		}
		vector<vector<string> > res;
		vector<string> one;
		helper(res, one, isPal, s, 0, n);
		return res;
    }
	void helper(vector<vector<string> >& res, vector<string>& one, vector<vector<bool> >& isPal, string s, int start, int size)
	{
		if(start==size){
			res.push_back(one);
		}
		for(int i=start;i<size;i++)
		{
			if(isPal[start][i])
			{
				one.push_back(s.substr(start,i-start+1));
				helper(res,one,isPal,s,i+1,size);
				one.pop_back();
			}
		}
	}
};


int main(){

}
