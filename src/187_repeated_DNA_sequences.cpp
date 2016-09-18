#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace::std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
		vector<string> res;
		if(s.size()<10) return res;
		unordered_map<string,int> umap;
		for(int i=0;i<s.size()-9;i++){
			string cur = s.substr(i,10);
			if(umap[cur]==1){
				res.push_back(cur);
			}
			umap[cur]++;
		}
		return res;
    }
};

int main(){
	Solution sol;
	vector<string> res = sol.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<endl;
	}

}
