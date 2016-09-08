#include<vector>
#include<string>
#include<iostream>
#include<array>
#include<unordered_set>

using namespace::std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		vector<string> res;
		vector<bool> possible(s.size()+1, true);
		helper(possible,res,"",s,0,wordDict);
		return res;
    }
	void helper(vector<bool>& possible, vector<string>& res, string one, string s, int start, unordered_set<string>& wordDict){
		if(start==s.size()){
			res.push_back(one.substr(0,one.size()-1));
			return;
		}
		for(int i=start;i<s.size();i++){
			string curstr = s.substr(start,i-start+1);
			if(wordDict.find(curstr)!=wordDict.end() && possible[i+1]){
				int before = res.size();
				helper(possible,res,one+curstr+" ",s,i+1,wordDict);
				if(res.size()==before) possible[i+1] = false;
			}
		}
	}
};

int main(){
	unordered_set<string> dict;
	array<string,2> arr = {"aaaa","aaa"};
	dict.insert(arr.begin(),arr.end());
	Solution sol;
	sol.wordBreak("aaaaaaa",dict);
}
