#include<iostream>
using namespace::std;
class Solution {
public:
    bool isPalindrome(int x) {
        long n=x;
        long rev=0;
        int dig=0;
        while(x>0){
            dig = x%10;
            rev = rev*10+dig;
            x /=10;
        }
        return n==rev?1:0;
    }
};

int main(){
	Solution s;
	int a=-12321;
	cout<<s.isPalindrome(a)<<endl;


}
