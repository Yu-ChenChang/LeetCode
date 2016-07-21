#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
    int trap(vector<int>& height) {
		if (height.empty()) { return 0; }
		int lo = 0;
		int hi = height.size() - 1;
		int sum = 0;
		int bound0 = height[lo];
		int bound1 = height[hi];
		while (lo+1 < hi) {
			if (bound0 < bound1) {
				int value = height[++lo];
				if (value < bound0) {
					sum += bound0 - value;
				} else {
					bound0 = value;
				}
			} else {
				int value = height[--hi];
				if (value < bound1) {
					sum += bound1 - value;
				} else {
					bound1 = value;
				}
			}
		}
		return sum;
	}
};

int main(){
	int array[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> height(array,array+12);
	Solution sol;
	int res = sol.trap(height);
	cout<<res<<endl;
}
