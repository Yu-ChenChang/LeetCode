#include<iostream>
#include<algorithm>
#include<vector>
using namespace::std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                for(int j=nums.size()-1;j>i;j--)
                {
                    if(nums[i]<nums[j])
                    {
                        swap(nums[i],nums[j]);
                        sort(nums.begin()+i+1,nums.end());
                        return;
                    }
                }
            }
        }
        sort(nums.begin(),nums.end());
        return;
    }
};

int main(){
	Solution sol;
	vector<int> num;
	num.push_back(1);
	num.push_back(3);
	num.push_back(2);
	sol.nextPermutation(num);
	for(int i=0;i<num.size();i++){
		cout<<num[i]<<" ";
	}
	cout<<endl;
	return 0;
}
