#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
		if(prices.empty()) return 0;
		int n = prices.size();
		if(k>=n) return maxProfit2(prices); //same as ultimate transaction
		vector<vector<int> > local(n,vector<int>(k+1,0)); //local[i][j]: the most profit for having at most j transaction at day i and must sell at day i
		vector<vector<int> > global(n,vector<int>(k+1,0));//global[i][j]: the most profit for having at most j transaction at day i (don't need to sell at day i)
		for(int i=1;i<n;i++){
			int diff = prices[i]-prices[i-1];
			for(int j=1;j<=k;j++){
				local[i][j] = max(global[i-1][j-1]+max(diff,0),local[i-1][j]+diff);
				//global[i-1][j-1]+max(diff,0): the most profit at day i-1 with at most j-1 transaction + whether buying at i-1 and selling at i add more profit.
				//local[i-1][j]+diff: the most profit at day i-1 with at most j transaction and sell at day i-1 + buying at i-1 and selling at i => the most profit at day i with at most j transaction and sell at day i (merge with diff and still remain j transaction
				global[i][j] = max(global[i-1][j],local[i][j]);
			}
		}
		return global[n-1][k];
    }
	int maxProfit2(vector<int>& prices){
		int res = 0;
		for(int i=1;i<prices.size();i++){
			int diff = prices[i]-prices[i-1];
			if(diff>0) res+=diff;
		}
		return res;
	}
};

int main(){

}
