#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
		vector<vector<int> > res;
		if(numRows<1) return res;
		res.push_back(vector<int>(1,1));
		for(int i=1;i<numRows;i++)
		{
			vector<int> one(1,1);
			for(int j=1;j<res[i-1].size();j++)
				one.push_back(res[i-1][j-1]+res[i-1][j]);
			one.push_back(1);
			res.push_back(one);
		}
       	return res; 
    }
};

int main(){

}
