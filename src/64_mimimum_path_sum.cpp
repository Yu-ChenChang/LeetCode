#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
	int minPathSum(vector<vector<int> >& grid) {
		if(grid.empty()) return 0;
    	int numOfRow = grid.size();
		int numOfCol = grid[0].size();
		int dp[numOfRow][numOfCol];
		dp[0][0] = grid[0][0];
		for(int row=1;row<numOfRow;row++) dp[row][0] = grid[row][0]+dp[row-1][0];
		for(int col=1;col<numOfCol;col++) dp[0][col] = grid[0][col]+dp[0][col-1];

		for(int row=1;row<numOfRow;row++)
			for(int col=1;col<numOfCol;col++)
				dp[row][col] = grid[row][col] + min(dp[row-1][col],dp[row][col-1]);
		
		return dp[numOfRow-1][numOfCol-1];
    }
};

int main(){


}
