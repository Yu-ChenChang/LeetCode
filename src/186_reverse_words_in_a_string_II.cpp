#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    void reverseWords(string &s) {
		int pos=0;
		for(int i=0;i<s.size();i++){
			if(s[i]==' '){
				reverse(s.begin()+pos,s.begin()+i);
				pos = i+1;
			}
		}
		reverse(s.begin()+pos,s.end());
		reverse(s.begin(),s.end());
    }
};

int main(){
	Solution sol;
	string s = "word is good";
	sol.reverseWords(s);
	cout<<s<<endl;

}
