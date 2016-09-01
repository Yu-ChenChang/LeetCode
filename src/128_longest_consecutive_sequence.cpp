#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace::std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
 		unordered_map<int,int> umap;       
		int maxLen = 0;
		for(int i=0;i<nums.size();i++)
		{
			if(umap[nums[i]]) continue;
			int left = 0;
			int right = 0;
			if(umap[nums[i]-1]) left = umap[nums[i]-1];
			if(umap[nums[i]+1]) right = umap[nums[i]+1];
			int len = right+left+1;
			maxLen = max(maxLen,len);
			umap[nums[i]] = len;
			if(umap[nums[i]-1])
			{
				umap[nums[i]-1-(umap[nums[i]-1]-1)] = len;
			}
			if(umap[nums[i]+1])
			{
				umap[nums[i]+1+(umap[nums[i]+1]-1)] = len;
			}
		}
		return maxLen;
    }
};

int main(){

}
