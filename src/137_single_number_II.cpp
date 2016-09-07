#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		vector<int> vec(32,0);
		int res = 0;
		int mask = 1;
		for(int i=31;i>=0;i--)
		{
			mask = 1<<i;
			for(int j=0;j<nums.size();j++)
			{
				if(nums[j]&mask)
					vec[i]++;
			}
			res = (res<<1) + vec[i]%3;
		}
		return res;
	}
};

int main(){
	vector<int> nums(4,2);
	nums[2] = 3;
	Solution sol;
	cout<<sol.singleNumber(nums)<<endl;

}
