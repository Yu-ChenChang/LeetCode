#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		if(nums.empty()) return;
		k = k%nums.size();
 		reverse(nums.begin(),nums.begin()+nums.size()-k);       
		reverse(nums.begin()+nums.size()-k,nums.end());
		reverse(nums.begin(),nums.end());
    }
};

int main(){

}
