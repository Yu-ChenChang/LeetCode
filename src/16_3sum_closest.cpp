#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<vector>
using namespace::std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return target;
        int res=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int le=i+1,ri=nums.size()-1;
            while(le<ri)
            {
                int sum = nums[i]+nums[le]+nums[ri];
                if(abs(target-sum)<abs(target-res))
                {
                    res = sum;
                }
                else
                {
                    if(sum>target) ri--;
                    else le++;
                }
            }
        }
        return res;
    }
};
int main(){
	Solution sol;
	int array[4] = {-1,2,1,-4};
	int target = 1;
	vector<int> num(array,array+4);
	cout<<sol.threeSumClosest(num,target)<<endl;

}
