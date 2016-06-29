#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
	bool validChar(char& c){
		if(c>='A'&&c<='Z') c = c+'a'-'A';
		else if((c<'a'||c>'z') && (c<'0'||c>'9')) return false;
		return true;
	}
    bool isPalindrome(string s) {
		if(s.empty()) return true;        
		int lIdx=0,rIdx = s.size()-1;
		while(lIdx<rIdx)
		{
			if(!validChar(s[lIdx])){
				lIdx++;
				continue;
			}
			if(!validChar(s[rIdx])){
				rIdx--;
				continue;
			}
			if(s[lIdx++]!=s[rIdx--])
				return false;
		}
		return true;
    }
};

int main(){
	string s = "0P";
	Solution sol;
	cout<<sol.isPalindrome(s)<<endl;
}
