#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    void reverseWords(string &s) {
		s+=' ';
		int pos = 0, wordlen = 0;
		for(int i=0;i<s.size();i++){
			if(s[i]!=' '){
				s[pos+wordlen] = s[i];
				wordlen++;
			}
			else if(wordlen!=0){
				reverse(s.begin()+pos,s.begin()+pos+wordlen);
				s[pos+wordlen] = ' ';
				pos += wordlen+1; //avoid space;
				wordlen = 0;
			}
		}
		if(pos==0) s.resize(0);
		else s.resize(pos-1);
		reverse(s.begin(),s.end());
    }
};

int main(){
	Solution sol;
	string s = "    word need to   reverse  ";
	sol.reverseWords(s);
	cout<<s<<endl;

}
