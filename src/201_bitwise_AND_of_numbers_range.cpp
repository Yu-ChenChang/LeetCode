#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int mask = INT_MAX;
        while((m&mask)!=(n&mask)){
            mask<<=1;
        }
        return m&mask;
    }
};

int main(){

}
