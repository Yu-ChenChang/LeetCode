#include<iostream>
#include<string.h>
using namespace::std;
class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[1000][1000] = {0};
		dp[0][0] = 1;
		for(int j=1;j<=p.size();j++)
		{
			for(int i=0;i<=s.size();i++)
			{
				if(dp[i-1][j-1] && i-1>=0 && j-1>=0)
				{
					if(s[i-1]==p[j-1] || p[j-1]=='.' || (p[j-1]=='*'&&(p[j-2]==s[i-1]||p[j-2]=='.'))) dp[i][j]=1;
				}
				if(dp[i-1][j] && i-1>=0)
				{
					if(p[j-1]=='*' && (p[j-2]==s[i-1]||p[j-2]=='.')) dp[i][j]=1;
				}
				if(dp[i][j-1] && j-1>=0)
				{
					if(p[j-1]=='*') dp[i][j]=1;
				}
				if(dp[i][j-2]&&j-2>=0)
				{
					if(p[j-1]=='*') dp[i][j]=1;
				}
			}
		}
		return dp[s.size()][p.size()];

    }
    bool isMatch_dp(const char *s, const char *p) {//DP version
        int i, j;
        int m = strlen(s);
        int n = strlen(p);

        /**
         * b[i + 1][j + 1]: if s[0..i] matches p[0..j]
         * if p[j] != '*'
         * b[i + 1][j + 1] = b[i][j] && s[i] == p[j]
         * if p[j] == '*', denote p[j - 1] with x,
         * then b[i + 1][j + 1] is true iff any of the following is true
         * 1) "x*" repeats 0 time and matches empty: b[i + 1][j -1]
         * 2) "x*" repeats 1 time and matches x: b[i + 1][j]
         * 3) "x*" repeats >= 2 times and matches "x*x": s[i] == x && b[i][j + 1]
         * '.' matches any single character
         */
        bool b[m + 1][n + 1];
        b[0][0] = true;
        for (i = 0; i < m; i++) {
            b[i + 1][0] = false;
        }
        // p[0..j - 2, j - 1, j] matches empty iff p[j] is '*' and p[0..j - 2] matches empty
        for (j = 0; j < n; j++) {
            b[0][j + 1] = j > 0 && '*' == p[j] && b[0][j - 1];
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (p[j] != '*') {
                    b[i + 1][j + 1] = b[i][j] && ('.' == p[j] || s[i] == p[j]);
                } else {
                    b[i + 1][j + 1] = b[i + 1][j - 1] && j > 0 || b[i + 1][j] ||
                                b[i][j + 1] && j > 0 && ('.' == p[j - 1] || s[i] == p[j - 1]);
                }
            }
        }
        return b[m][n];
    }
    bool isMatch(const char *s, const char *p) {//recursive version
		if(!*p) return !*s;
		
		if(*(p+1) == '*'){
			return (isMatch(s,p+2)||*s&&(*s==*p || *p == '.')&&isMatch(s+1,p));
		}
		else{
			if(!*s) return false;
			return (*s==*p||*p=='.')?isMatch(s+1,p+1):false;
		}
	}

};

int main(int argc,char** argv){
	Solution sol;
	cout<<"Enter two string for compare: "<<endl;
	char s[30] ;
	char p[30] ;
	cin>>s;
	cin>>p;
	cout<<sol.isMatch(s,p)<<endl;
}
