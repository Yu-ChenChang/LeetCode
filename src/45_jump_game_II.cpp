#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
    int jump(vector<int>& nums) {
		if(nums.size()<=1) return 0;
		int* Step = new int[nums.size()](); //save previous steps
		//int* Pre = new int[nums.size()](); //used for saving the route
		bool* NotValid = new bool[nums.size()](); //filter out unnecessary jump nums for time enhancement

		for(int i=0;i<nums.size();i++)
		{
			if(NotValid[i]) continue;
			for(int j=1;j<=nums[i]&&i+j<nums.size();j++)
			{
				//the jump distance of the nums is within the previous jump (unnecessary jump)
				if(i+j+nums[i+j]<=i+nums[i])
				{
					if(i+j != nums.size()-1)
					{
						NotValid[i+j] = true;
						continue;
					}
				}

				if(Step[i]+1<Step[i+j] || Step[i+j]==0)
				{
					Step[i+j] = Step[i]+1;
					//Pre[i+j] = Pre[i];
				}
			}
		}
		return Step[nums.size()-1];
    }
};

int main(){
	int arr[] ={2,1,2,1,1,1,2,4};// {2,3,1,1,4};
	vector<int> nums(arr,arr+sizeof(arr)/sizeof(int));
	Solution sol;

	cout<<sol.jump(nums)<<endl;
}
