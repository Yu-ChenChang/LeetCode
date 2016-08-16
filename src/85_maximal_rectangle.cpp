#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
using namespace::std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if(matrix.empty()) return 0;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int> > dp(m,vector<int>(n,0));
		for(int j=0;j<n;j++)
			dp[0][j] = matrix[0][j]=='1';
		for(int i=1;i<m;i++)
			for(int j=0;j<n;j++)
				dp[i][j] = matrix[i][j]=='0'?0:dp[i-1][j]+1;

		int maximum = 0;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				int width = dp[i][j];
				for(int k=j;k>=0;k--)
				{
					width = min(width,dp[i][k]);
					maximum = max(maximum,(j-k+1)*width);
				}
			}
		return maximum;
    }

    int maximalRectangle_opt(vector<vector<char> >& matrix) {
		if(matrix.empty()) return 0;

		int result = 0;
		vector<int> height(matrix[0].size()+1,0);
		for(int i=0;i<matrix.size();i++)
		{
			for(int j=0;j<matrix[0].size();j++)
				height[j] = matrix[i][j]=='1'?height[j]+1:0;
			//largerest rectangle in histogram
			stack<int> pos;
			for(int j=0;j<height.size();j++)
			{
				while(!pos.empty() && height[pos.top()]>height[j])
				{
					int top = pos.top();
					pos.pop();
					int nextTop = pos.empty()?-1:pos.top();
					result = max((j-nextTop-1)*height[top],result);
				}
				pos.push(j);
			}
		}
		return result;
    }
};

int main(){
	Solution sol;
	vector<char> row(2,'1');
	vector<vector<char> >matrix(1,row);
	cout<<sol.maximalRectangle(matrix)<<endl;
}
