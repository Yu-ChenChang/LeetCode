#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
using namespace::std;

class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0) return a;
        int sum = a ^ b;
        int carry = (a & b) << 1;
        return getSum(sum, carry);
    }
};

int main(){
	Solution sol;
	cout<<sol.getSum(2,3)<<endl;
}
