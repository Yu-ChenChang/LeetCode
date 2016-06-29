#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		if(prices.empty()) return 0;
		int res = 0;
		int curMin = prices[0];
        for(int i=1;i<prices.size();i++)
		{
			if(prices[i]<=curMin)
				curMin = prices[i];
			else
				res = prices[i]-curMin>res?prices[i]-curMin:res;
		}
		return res;
    }
};

int main(){

}
