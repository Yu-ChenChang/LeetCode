#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		if(ratings.empty()) return 0;
		int n = ratings.size();
		vector<int> candy(n,0);
		candy[0] = 1;
		int curR = ratings[0];
		int res = 1;
		for(int i=1;i<n;i++){
			if(ratings[i]>ratings[i-1]){
				candy[i] = candy[i-1]+1;
			}
			else candy[i] = 1;
		}

		for(int i=n-2;i>=0;i--) {
			if(ratings[i]>ratings[i+1] && candy[i]<=candy[i+1]) {
				candy[i] = candy[i+1]+1;
			}
		}
		int sum=0;
		for(int i=0;i<n;i++)
			sum+=candy[i];
		return sum;
	}
};

int main(){

}
