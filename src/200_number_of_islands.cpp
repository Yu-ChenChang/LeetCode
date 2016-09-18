#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
		if(grid.empty()) return 0;
		int m = grid.size();
		int n = grid[0].size();
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(grid[i][j]=='1'){
					dfs(grid,i,j);
					grid[i][j] = '1';
				}
			}
		}
		int res = 0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(grid[i][j]=='1') res++;
			}
		}
		return res;
    }
	void dfs(vector<vector<char> >& grid,int curi, int curj){
		int m = grid.size();
		int n = grid[0].size();
		grid[curi][curj] = '0';
		if(curi>0 && grid[curi-1][curj]=='1') dfs(grid,curi-1,curj);
		if(curi<m-1 && grid[curi+1][curj]=='1') dfs(grid,curi+1,curj);
		if(curj>0 && grid[curi][curj-1]=='1') dfs(grid,curi,curj-1);
		if(curj<n-1 && grid[curi][curj+1]=='1') dfs(grid,curi,curj+1);
	}
};

int main(){
	vector<vector<char> > grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
	Solution sol;
	cout<<sol.numIslands(grid)<<endl;
}
