#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
	int climbStairs(int n) {
		n++;
		int* dp = new int[n]();
		dp[0] = 1;
		dp[1] = 1;
		for(int i=2;i<n;i++)
		{
			dp[i] = dp[i-1]+dp[i-2];
		}
		return dp[n-1];
	}
};

int main(){
	Solution sol;
	cout<<sol.climbStairs(4)<<endl;

}
