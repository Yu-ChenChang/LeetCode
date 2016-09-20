#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    string reverseString(string s) {
		if(s.size()<2) return s;
		int left = 0, right = s.size()-1;
		while(left<right){
			char c = s[left];
			s[left] = s[right];
			s[right] = c;
			left++;
			right--;
		}
		return s;
    }
};

int main(){

}
