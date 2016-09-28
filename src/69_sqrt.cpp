#include<iostream>
using namespace::std;

class Solution {
public:
	int mySqrt(int x) {
		int left = 0, right = x;
		while(left<right){
			int mid = (left+right)>>1;
			if(mid*mid==x) return mid;
			else if(mid!=0&&mid>INT_MAX/mid || mid*mid>x) right = mid-1;
			else left = mid+1;
		}
		return left*left>x?left-1:left;
	}
};

int main(){
	Solution sol;
	cout<<sol.mySqrt(81)<<endl;
	cout<<46340*46340<<endl;
}
