#include<vector>
#include<string>
#include<iostream>
using namespace::std;

struct compare{
	bool operator()(int &x, int &y) const{
		string xs = to_string(x);
		string ys = to_string(y);
		return (xs+ys)>(ys+xs);
	}
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
		string res;
		sort(nums.begin(),nums.end(),compare());
		if(nums[0]==0) return "0";
		for(int i=0;i<nums.size();i++){
			res += to_string(nums[i]);
		}
		return res;
    }
};

int main(){
	vector<int> nums = {3,30,34,5,9};
	Solution sol;
	cout<<sol.largestNumber(nums)<<endl;
}
