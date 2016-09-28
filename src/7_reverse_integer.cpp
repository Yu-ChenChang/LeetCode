#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace::std;

class Solution {
public:
    int reverse(int x)
	{
        bool sign = (x>=0);
        if(x<0) x=-x;
        int res=0;
        while(x>0){
            if(res>(INT_MAX-x%10)/10) return 0;
            res = res*10+x%10;
            x /= 10;
        }
        return sign?res:-res;
    }
};

int main(int argc,char** argv){
	Solution s;
	int num = 1534236469;
	cout<<s.reverse(num)<<endl;

	return 0;
}
