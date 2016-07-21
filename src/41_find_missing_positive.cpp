#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
    void swap(int& a,int& b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    int firstMissingPositive(vector<int>& nums) {
        if(!nums.size()) return 1;
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]>0 && nums[nums[i]-1]!= nums[i] && nums[i]-1<nums.size())
            {
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if((i+1)!=nums[i])
                return i+1;
        }
        return nums[nums.size()-1]+1;
    }
};

int main(){

}
