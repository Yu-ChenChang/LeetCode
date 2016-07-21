#include<iostream>
using namespace::std;
class Solution {
public:
    int divide(int dividend, int divisor) {
		bool sign = !((dividend<0) ^ (divisor<0));
		if(dividend>0) dividend = -dividend;
		if(divisor>0) divisor = -divisor;
		if(dividend>divisor || dividend==0 || divisor==0) return 0;
		int sum=0;
		int cur=1;
		while(divisor<<1 > dividend && divisor<<1 <0)
		{
			divisor <<=1;
			cur <<=1;
		}

		while(dividend<0)
		{
			if(dividend - divisor >0)
			{
				divisor >>=1;
				if(cur==1) break;
				else cur >>=1;
			}
			else
			{
				dividend -=divisor;
				sum += cur;
			}	
		}
		return sign?(sum<0?INT_MAX:sum):-sum;
    }
};

int main(){
	Solution sol;
	cout<<"Result should be -50: "<<sol.divide(100, -2)<<endl;
	cout<<"Result should be 33: "<<sol.divide(100, 3)<<endl;
	cout<<"Result should be 1073741823: "<<sol.divide(INT_MAX, 2)<<endl;
	cout<<"Result should be 715827882: "<<sol.divide(INT_MIN, -3)<<endl;
	cout<<"Result should be -1: "<<sol.divide(1100540749, -1090366779)<<endl;
	
}
