#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
		vector<int> res(rowIndex+1,0);        
		res[0] = 1;
		for(int i=1;i<=rowIndex;i++)
		{
			int pre = res[0];
			for(int j=1;j<=rowIndex;j++)
			{
				int tmp = res[j];
				res[j] += pre;
				pre = tmp;
			}
		}
		return res;
    }
};

int main(){

}
