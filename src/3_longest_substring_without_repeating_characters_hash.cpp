#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace::std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int res = 0;
		int curl = 0;
		unordered_map<char,int> umap; //<character, index>
		for(int i=0;i<s.size();i++){
			if(umap.find(s[i])!=umap.end() && i-umap[s[i]]<=curl){
				res = max(res,curl);
				curl = i-umap[s[i]];
				umap[s[i]] = i;
			}
			else{
				umap[s[i]] = i;
				curl++;
			}
		}
		return max(res,curl);
    }
};

int main(){
	Solution sol;
	cout<<sol.lengthOfLongestSubstring("abba")<<endl;
}
