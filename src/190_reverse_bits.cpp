#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
		uint32_t res = 0;
		for(int i=0;i<32;i++){
			int bit = n & 0x1;
			n>>=1;
			res<<=1;
			res |= bit;
		}
		return res;
    }
};

int main(){
	Solution sol;
	cout<<sol.reverseBits(1)<<endl;

}
