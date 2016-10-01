#include<vector>
#include<string>
#include<iostream>
using namespace::std;

// similar problem: maxSubArray <=k
class Solution {
public:
	//minSubArray >= s
    int minSubArrayLen(int s, vector<int>& nums) {
		if(nums.empty()) return 0;
		int start = 0, len =0;
		int minlen =INT_MAX, sum = 0;
		for(int i=0;i<nums.size();i++){
			sum+=nums[i];
			len++;
			while(sum>=s && len>0){
				minlen = min(minlen,len);
				sum-=nums[start++];
				len--;
			}
		}
		return minlen==INT_MAX?0:minlen;
    }
};

int main(){
	vector<int> nums = {5,1,3,5,10,7,4,9,2,8};
	cout<<Solution().minSubArrayLen(15,nums)<<endl;
}
