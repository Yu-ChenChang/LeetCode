#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
	bool isScramble(string s1, string s2){
		//return isScramble_recursize(s1,s2);
		return isScramble_dp(s1,s2);
	}
private:
    bool isScramble_recursive(string s1, string s2) {
        if(s1==s2)
            return true;

        int len = s1.length();
        int count[26] = {0};
        for(int i=0; i<len; i++)
        {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }

        for(int i=0; i<26; i++)
        {
            if(count[i]!=0)
                return false;
        }

        for(int i=1; i<=len-1; i++)
        {
            if( isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if( isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
                return true;
        }
        return false;
    }
    bool isScramble_dp(string s1, string s2) {
        int len=s1.size();
        bool dp[100][100][100]={false};
        for (int i=len-1;i>=0;i--)
            for (int j=len-1;j>=0;j--) {
                dp[i][j][1]=(s1[i]==s2[j]);
                for (int l=2;i+l<=len && j+l<=len;l++) {
                    for (int n=1;n<l;n++) {
                        dp[i][j][l]|=dp[i][j][n]&&dp[i+n][j+n][l-n];
                        dp[i][j][l]|=dp[i][j+l-n][n]&&dp[i+n][j][l-n];
                    }
                }
            }
        return dp[0][0][len];
    }
};

int main(){
	Solution sol;
	cout<<sol.isScramble("abcd","badc")<<endl;
	cout<<sol.isScramble("abcd","dacb")<<endl;
	cout<<sol.isScramble("abc","cab")<<endl;
	cout<<sol.isScramble("gregrat","regrgat")<<endl;
	cout<<sol.isScramble("grgreat","regrgat")<<endl;
}
