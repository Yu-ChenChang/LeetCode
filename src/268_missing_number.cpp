#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
		int n = nums.size();
		int res = n;
		int sum = 0;
		for(int i=0;i<n;i++){
			res += i;
			sum += nums[i];
		}
		return res-sum;
    }
};

int main(){

}
