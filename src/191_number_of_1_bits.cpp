#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
		int res =0;
		while(n){
			if((n&0x1)==1) res++;
			n>>=1;
		}
		return res;
    }
};

int main(){

}
