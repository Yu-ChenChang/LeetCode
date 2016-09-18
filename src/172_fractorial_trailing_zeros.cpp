#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
	int trailingZeroes(int n) {
		int res=0;
		int five = 5;
		while(n>=five){
			res += n/five;
			if(five>INT_MAX/5) break;
			five *= 5;
		}
		return res;
	}
};

int main(){

}
