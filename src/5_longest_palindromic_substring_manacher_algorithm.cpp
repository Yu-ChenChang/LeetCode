#include<string>
#include<iostream>
#include<algorithm>
using namespace::std;
class Solution {
public:
	string preprocessing(string s)
	{
		string s2;
		for(int i=0;i<s.size();i++)
		{
			s2+="#";
			s2+=s[i];			
		}
		s2+="#";
		return s2;
	}
    string longestPalindrome(string s)
 	{
		string s2 = preprocessing(s);
		int C=0,R=0;
		int P[2001] = {0};
		int maxi=0;

		for(int i=0;i<s2.size();i++)
		{
			//Initiate P[i]
			P[i] = (R > i) ? min(R-i, P[C-(i-C)]) : 0;	
			// Attempt to expand palindrome centered at i
			while (i+1+P[i]<s2.size()&&i-1-P[i]>=0&&s2[i + 1 + P[i]] == s2[i - 1 - P[i]]) P[i]++;

			// If palindrome centered at i expand past R,
			// adjust center based on expanded palindrome.
			if(i+P[i]>R)
			{
				C = i;
				R = i+P[i];
			}
			maxi = P[i]>P[maxi]?i:maxi;
		}
		return s.substr((maxi-P[maxi]+1)/2,P[maxi]);
    }
};
int main(int argc,char** argv){
	string s1 = "abccba";
	string s2 = "eabccbafgie";
	string s3 = "aaabaaaa";
	Solution so;
	cout<<so.longestPalindrome(s1)<<endl;
	cout<<so.longestPalindrome(s2)<<endl;
	cout<<so.longestPalindrome(s3)<<endl;
}
