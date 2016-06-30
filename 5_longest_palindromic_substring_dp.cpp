#include<string>
#include<iostream>
#include<algorithm>
using namespace::std;
class Solution {
public:
    string longestPalindrome(string s)
 	{
		int start=0,maxlen=0;
		bool isPal[1000][1000] = {false};
		for(int i=0;i<s.size();i++)
		{
			for(int j=i;j>=0;j--)
			{
				if((i-j<2 || isPal[i-1][j+1])&&s[i]==s[j])
				{
					isPal[i][j] = true;
					if(i-j+1>maxlen)
					{
						maxlen = i-j+1;
						start = j;
						//end = i;
					}
				}
			}
		}
		return s.substr(start,maxlen);
    }
};
int main(int argc,char** argv){
	string s1 = "abb";//"abccba";
	string s2 = "eabccbafgie";
	string s3 = "aaabaaaa";
	Solution so;
	cout<<so.longestPalindrome(s1)<<endl;
	cout<<so.longestPalindrome(s2)<<endl;
	cout<<so.longestPalindrome(s3)<<endl;
}
