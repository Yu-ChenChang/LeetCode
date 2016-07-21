#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
    	vector<vector<int> >res;
		vector<int> row(n,0);
		for(int i=0;i<n;i++) res.push_back(row);
		
		int startR=0,startC=0;
		int endR = n-1, endC = n-1;
		int num = 0;
		while(startR<=endR && startC<=endC)
		{
			for(int col = startC;col<=endC;col++)
				res[startR][col] = ++num;
			startR++;
			for(int row = startR;row<=endR;row++)
				res[row][endC] = ++num;
			endC--;
			if(startR<=endR)
			{
				for(int col = endC;col>=startC;col--)
					res[endR][col] = ++num;
				endR--;
			}
			if(startC<=endC)
			{
				for(int row = endR;row>=startR;row--)
					res[row][startC] = ++num;
				startC++;
			}
		}
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
