#include<iostream>
#include<vector>
#include<unordered_map>
using namespace::std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
			unordered_map<int,int> umap; // <value, index>
			vector<int> res;
			for(int i=0;i<nums.size();i++)
			{
				if(umap[target-nums[i]] != 0)
				{
					res.push_back(umap[target-nums[i]]-1);
					res.push_back(i);
				}
				umap[nums[i]] = i+1; //add 1 to avoid 0
			}
			return res;

    }
};

int main(){
}

