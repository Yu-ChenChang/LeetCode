#include<iostream>
using namespace::std;

class Solution {
public:
	int mySqrt(int x) {
		if(x<0||x==0) return 0;
		int max = 46340;
		int min = 0;
		int mid;
		while(max>min+1)
		{
			mid = (max+min)/2;
			if(mid*mid>x || mid*mid<0) max = mid;
			else if(mid*mid<x) min = mid;
			else return mid;
		}
		return max*max<=x?max:min;
	}
};

int main(){
	Solution sol;
	cout<<sol.mySqrt(81)<<endl;
	cout<<46340*46340<<endl;
}
