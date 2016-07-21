#include<iostream>
#include<vector>
#include<string>
using namespace::std;

class Solution {
public:
	bool forwardPos(vector<int>& pos,int n,int k){
		int carry=0;
		while(true)
		{
			int i;
			for(i=k-1;i>=0;i--)
			{
				if(pos[i]<n-1-(k-1-i))
				{
					pos[i]++;
					for(int j=i+1;j<=k-1;j++)
						pos[j] = pos[j-1]+1;	
					return true;
				}
				else if(i==0) return false;
			}
		}
	}

    vector<vector<int> > combine(int n, int k) {
		vector<vector<int> >res;
		vector<int> ans;
		if(n<k) return res;
		vector<int> pos(k,0);

		for(int i=0;i<k;i++)
		{
			pos[i] = i;
			ans.push_back(pos[i]+1);
		}
		res.push_back(ans);
		while(forwardPos(pos,n,k))
		{	
			ans.clear();
			for(int i=0;i<k;i++)	
				ans.push_back(pos[i]+1);
			res.push_back(ans);
		}
				
		return res;
    }

};

int main(){
	Solution sol;
	vector<vector<int> >res = sol.combine(5,3);

	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
}
