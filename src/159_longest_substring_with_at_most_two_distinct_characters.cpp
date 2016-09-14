#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace::std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
		if(s.empty()) return 0;
		unordered_map<char,int> umap;
		vector<int> dp(s.size(),0);
		dp[0] = 1;
		int res = 1;
		umap[s[0]]++;
		int curC = 1;

		for(int i=1;i<s.size();i++){
			if(umap[s[i]]>0 || (curC<2)){
				if(!umap[s[i]]) curC++;
				dp[i] = dp[i-1]+1;
				umap[s[i]]++;
			}
			else{
				dp[i] = dp[i-1]+1;
				curC++;
				umap[s[i]]++;
				while(curC>2){
					dp[i]--;
					umap[s[i-dp[i]]]--;
					if(!umap[s[i-dp[i]]]) curC--;
				}
			}
			res = max(res,dp[i]);
		}
		return res;
    }
};

int main(){
	Solution sol;
	cout<<sol.lengthOfLongestSubstringTwoDistinct("abcabcabc")<<endl;

}
