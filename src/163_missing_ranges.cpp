#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<string> res;
		int start = lower;
		for(int i=0;i<nums.size();i++){
			if(nums[i]==start){
				start++;
			}
			else{
				int end = nums[i]-1;
				if(end-start==0){
					res.push_back(to_string(start));
				}
				else{
					res.push_back(to_string(start)+"->"+to_string(end));
				}
				start = nums[i]+1;
			}
		}
		if(start>upper) return res;
		else if(upper-start==0) res.push_back(to_string(start));
		else res.push_back(to_string(start)+"->"+to_string(upper));

		return res;
    }
};

int main(){

}
