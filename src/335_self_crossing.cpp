#include<iostream>
#include<string.h>
#include<vector>
using namespace::std;
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
		if(x.size()<4) return false;
		int n = x.size();
		bool decreasing = (x[2]<=x[0]);
		for(int i=3;i<n;i++)
		{
			if(decreasing)
			{
				if(x[i]>=x[i-2]) return true;
			}
			else if(x[i]<=x[i-2])
			{
				if(x[i]==x[i-2])
				{
					x[i-1] = x[i-1] - x[i-3];
					decreasing = true;
				}
				else if(i-4>=0 && x[i]>=x[i-2]-x[i-4])
				{
					x[i-1] = x[i-1] - x[i-3];
					decreasing = true;
				}
			}
		}

		return false;
    }
};

int main(int argc,char** argv){

}
