#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
		if(dungeon.empty()) return -1;
		int m = dungeon.size();
		int n = dungeon[0].size();
		vector<vector<int> > dp(m,vector<int>(n,0)); //<cur,min>
		dp[m-1][n-1] = max(1-dungeon[m-1][n-1],1);
		for(int i=m-2;i>=0;i--){
			dp[i][n-1] = max(dp[i+1][n-1]-dungeon[i][n-1],1);
		}
		for(int j=n-2;j>=0;j--){
			dp[m-1][j] = max(dp[m-1][j+1]-dungeon[m-1][j],1);
		}
		for(int i=m-2;i>=0;i--){
			for(int j=n-2;j>=0;j--){
				int down = max(dp[i+1][j]-dungeon[i][j],1);
				int right = max(dp[i][j+1]-dungeon[i][j],1);
				dp[i][j] = min(down,right);
			}
		}
		return dp[0][0];
    }
};

int main(){
	vector<vector<int> > dg = {{1,-3,3},{0,-2,0},{-3,-3,0}};
	Solution sol;
	cout<<sol.calculateMinimumHP(dg)<<endl;

}