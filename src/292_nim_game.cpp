#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    bool canWinNim(int n) {
        if(n<=3) return true;
        if(n%4==0) return false;
        else return true;
    }
};

int main(){

}
