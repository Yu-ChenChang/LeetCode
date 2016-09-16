#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
		int m = s.size();
		int n = t.size();
		if(m<n) return isOneEditDistance(t,s);
		if(m-n>1) return false;

		int edit = 0;
		int x=0;
		for(int i=0;i<m;){
			if(s[i+x]!=t[i]){
				edit++;
				if(edit>1) return false;
				if(m>n) x=1;
				else i++;
			}
			else i++;
		}
		return (edit==1);
    }
};

int main(){
	Solution sol;
	cout<<sol.isOneEditDistance("ab","acd")<<endl;

}
