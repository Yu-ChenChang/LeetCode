#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    vector<int> grayCode(int n) {
		if(n<1) return vector<int>(1,0);
		int arr[] = {0,1};
		vector<int> res(arr,arr+sizeof(arr)/sizeof(int));
		int value = 2;
		for(int i=1;i<n;i++)
		{
			for(int j=res.size()-1;j>=0;j--)
			{
				res.push_back(value+res[j]);
			}
			value*=2;
		}
		return res;
    }
};

int main(){
	Solution sol;
	vector<int> res = sol.grayCode(3);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl;
}
