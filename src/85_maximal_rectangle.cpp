#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
using namespace::std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
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
	vector<char> row(1,'1');
	vector<vector<char> >matrix(1,row);
	cout<<sol.maximalRectangle(matrix)<<endl;
}
