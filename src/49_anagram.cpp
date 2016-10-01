#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace::std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
		vector<vector<string> > res;
		unordered_map<string, vector<string> > umap;
		vector<string> copy(strs);
		for(int i=0;i<copy.size();i++){
			sort(copy[i].begin(),copy[i].end());
		}
		for(int i=0;i<copy.size();i++){
			umap[copy[i]].push_back(strs[i]);
		}
		for(unordered_map<string, vector<string> >::iterator it=umap.begin();it!=umap.end();it++){
			res.push_back(it->second);
		}
		return res;
    }
};

int main(){
	string str = "dcba";
	sort(&str[0],&str[0]+4);
	cout<<str<<endl;
}
