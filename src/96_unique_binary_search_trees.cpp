#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    int numTrees(int n) {
        if(n == 0) return 0;

        vector<int> nums(n + 1, 0);
        nums[0] = 1;

        for(int nodeNum = 1; nodeNum<= n; nodeNum++)
            for(int k = 1; k <= nodeNum; k++)
                nums[nodeNum] += nums[k - 1] * nums[nodeNum - k];

        return nums[n];
    }
};

int main(){
	Solution sol;
	cout<<sol.numTrees(6)<<endl;
}
