#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace::std;

class Solution {
public:
    int reverse(int x)
	{
        int value = x>0?x:-x;
        int res = 0;
        while(value>0)
        {
            if(res>INT_MAX/10) return 0;
            res *= 10;
            if(res>INT_MAX-value%10) return 0;
            res += value%10;
            value /= 10;
        }
        return x>0?res:-res;
    }
};

int main(int argc,char** argv){
	Solution s;
	int num = 1534236469;
	cout<<s.reverse(num)<<endl;

	return 0;
}
