#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace::std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		if(nums.empty()) return;
		int n = nums.size();
		int zptr = 0, nptr = 0;        
		while(zptr<n && nptr<n){
			while(zptr<n && nums[zptr]!=0) zptr++;
			while(nptr<zptr || (nptr<n && nums[nptr]==0)) nptr++;
			if(zptr<n && nptr<n){
				swap(nums[zptr],nums[nptr]);
			}
		}
    }
};

int main(){
}
