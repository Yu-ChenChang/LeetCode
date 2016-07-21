#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace::std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
		if(height.empty()) return 0;
		height.push_back(0); //dummy height
		int result = 0;
		vector<int> vec;
		for(int i=0;i<height.size();i++)
		{
			while(!vec.empty() && height[vec[vec.size()-1]] > height[i])
			{
				int top = vec[vec.size()-1];
				vec.pop_back();
				int nextTop = vec.empty()?-1:vec[vec.size()-1];
				result = max((i-nextTop-1)*height[top],result);
			}
			vec.push_back(i);
		}
		return result;
	}
};

int main(){
	int arr[] = {2,1,5,6,2,3};
	int arr2[] = {4,2,0,3,2,4,3,4};
	vector<int> height(arr,arr+sizeof(arr)/sizeof(int));
	vector<int> height2(arr2,arr2+sizeof(arr2)/sizeof(int));
	Solution sol;
	cout<<sol.largestRectangleArea(height)<<endl;
	cout<<sol.largestRectangleArea(height2)<<endl;
}
