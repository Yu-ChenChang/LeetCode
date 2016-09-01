#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
		vector<vector<int > > res(n,vector<int>(n,0));
		int num = 1;
		int i=0;
		int j=0;
		int cn=n;
		while(cn>1)
		{
			for(int k=0;k<cn-1;k++)
				res[i][j++] = num++;
			for(int k=0;k<cn-1;k++)
				res[i++][j] = num++;
			for(int k=0;k<cn-1;k++)
				res[i][j--] = num++;
			for(int k=0;k<cn-1;k++)
				res[i--][j] = num++;
			//update parameter
			i++;
			j++;
			cn-=2;
		}
		if(cn==1) res[i][j] = num++;
		return res;
    }
};

int main(){
	Solution sol;
	vector<vector<int> > res = sol.generateMatrix(3);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
		{
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}
