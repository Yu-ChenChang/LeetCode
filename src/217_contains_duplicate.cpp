#include<iostream>
#include<vector>
#include<unordered_map>
using namespace::std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_map<int,int> umap;
		for(vector<int>::iterator it=nums.begin();it!=nums.end();it++){
			umap[*it] += 1;
			if(umap[*it]>1) return true;
		}
		return false;
	}
};

int main(){

}
