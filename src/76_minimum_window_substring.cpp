#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace::std;

class Solution {
public:
    string minWindow(string s, string t) {
        //unordered_map<char,int> umap; 
        vector<int> umap(128,0); //faster
		for(int i=0;i<t.size();i++)
			umap[t[i]]++;
		int required = t.size();
		int start = 0;
		int min = -1, minS = 0;
		int i=0;
		while(i<=s.size()&&start<s.size())
		{
			if(required)
			{
				if(i==s.size()) break;
				if(umap[s[i]]>0) required--;
				umap[s[i]]--;
				i++;
			}
			else
			{
				if(i-start<min || min<0)
				{
					min = i-start;
					minS = start;
				}
				umap[s[start]]++;
				if(umap[s[start]]>0) required++;
				start++;
			}
		}
		return min<0?"":s.substr(minS,min);
    }
};

int main(){
	Solution sol;
	string res;
	res = sol.minWindow("ADOBECODEBANC","ABC");
	cout<<res<<endl;
	res = sol.minWindow("A","A");
	cout<<res<<endl;
}
