#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace::std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
		if(triangle.empty()) return 0;
		int k = triangle.size();
		vector<int> dp(k,0);
		dp[0] = triangle[0][0];
		for(int i=1;i<k;i++)
		{
			int pre = dp[0];
			dp[0] += triangle[i][0];
			for(int j=1;j<i+1;j++)
			{
				int cur = dp[j];
				if(j==i)
					dp[j] = triangle[i][j] + pre;
				else
					dp[j] = triangle[i][j] + (cur<pre?cur:pre);
				pre = cur;
			}
		}
		int min = INT_MAX;
		for(int i=0;i<k;i++)
			min = dp[i]<min?dp[i]:min;
       	return min; 
    }
};

int main(){

}
