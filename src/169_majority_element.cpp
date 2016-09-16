#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace::std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj = nums.size()/2;
        unordered_map<int,int> umap;
        for(int i=0;i<n;i++){
            umap[nums[i]]++;
            if(umap[nums[i]]>maj) return nums[i];
        }
        return 0;
    }
};

int main(){

}
