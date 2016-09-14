#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace::std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
		if(s.empty() || k<1) return 0;
		unordered_map<char,int> umap;
		vector<int> dp(s.size(),0);
		dp[0] = 1;
		int res = 1;
		umap[s[0]]++;
		int curC = 1;

		for(int i=1;i<s.size();i++){
			if(umap[s[i]]>0 || (curC<k)){
				if(!umap[s[i]]) curC++;
				dp[i] = dp[i-1]+1;
				umap[s[i]]++;
			}
			else{
				dp[i] = dp[i-1]+1;
				curC++;
				umap[s[i]]++;
				while(curC>k){
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
}
