#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
		int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

		for(int i=0;i<rows;i++)
			for(int j=0;j<cols;j++)
				if(matrix[i][j]==0)
				{
					if(j!=0)
					{

						matrix[0][j]=0;
						matrix[i][0]=0;
					}
					else
						col0=0;
				}

		for(int i=rows-1;i>=0;i--)
			for(int j=cols-1;j>=0;j--)
				if(j!=0&&(matrix[i][0]==0||matrix[0][j]==0) || j==0&&col0==0) matrix[i][j]=0;
    }
};

int main(){
	Solution sol;


}
