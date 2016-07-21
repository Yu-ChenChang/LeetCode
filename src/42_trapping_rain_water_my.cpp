#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
    int trap(vector<int>& height) {
		if(height.empty()) return 0;
		int left = 0;
		int right = height.size()-1;
		int boundL = height[left];
		int boundR = height[right];
		int sum = 0;
		while(left+1<right)
		{
			if(boundL<boundR)
			{
				int value = height[++left];
				if(boundL>value)
				{
					sum+=boundL-value;
				}
				else
				{
					boundL = value;
				}	
			} 
			else
			{
				int value = height[--right];
				if(boundR>value)
				{
					sum+=boundR-value;
				}
				else
				{
					boundR = value;
				}
			}

		}	
		return sum;
	}
};

int main(){
	int array[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> height(array,array+12);
	Solution sol;
	int res = sol.trap(height);
	cout<<res<<endl;
}
