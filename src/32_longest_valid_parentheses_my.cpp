#include<iostream>
#include<string.h>
#include<vector>
using namespace::std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int curMax = 0;
        vector<int> dp(s.size()+1,0);
        for(int i=1; i < s.size(); i++){
            if(s[i] == ')' && i-dp[i]-1 >= 0 && s[i-dp[i]-1] == '('){
                    dp[i+1] = dp[i] + 2 + dp[i-dp[i]-1];
                    curMax = max(dp[i+1],curMax);
            }
        }
        return curMax;
    }
};

int main(){
	Solution sol;
	string s1 = "())";
	string ss = "(()()(()(()))()((()))((()(()())()(()))())))()(()()))())))))))()()()()))(((()())((()()(((())))()(()()(())((()))))))(()(()))(((()())()))(()))((((()(()()()())()()(()))(()()(())()((()()())))(())()())()(";
	cout<<sol.longestValidParentheses(ss)<<endl;
	/*
	string s2 = "(";
	string s3 = "()(()";
	string s4 = ")()(((())))(";
	string s5 = "(()(((()";
	cout<<s1<<" "<<sol.longestValidParentheses(s1)<<endl;
	cout<<s2<<" "<<sol.longestValidParentheses(s2)<<endl;
	cout<<s3<<" "<<sol.longestValidParentheses(s3)<<endl;
	cout<<s4<<" "<<sol.longestValidParentheses(s4)<<endl;
	cout<<s5<<" "<<sol.longestValidParentheses(s5)<<endl;
	*/
}
