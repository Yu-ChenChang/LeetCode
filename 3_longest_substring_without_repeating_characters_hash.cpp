#include<iostream>
#include<unordered_map>
#include<string>
using namespace::std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		unordered_map<char,int> umap; //<character, index>
		int max=0,start=1;
		for(int i=0;i<s.size();i++)
		{
			if(umap[s[i]]!=0)
			{
				start = (umap[s[i]]+1)>start?(umap[s[i]]+1):start;
			}
			umap[s[i]] = i+1; //avoid 0, index start with 1
			int len = (i+1)-start+1;
			max = len>max?len:max;
		}
		return max;
    }
};
int main(){
	string s = "ccc";
	Solution sol;
	cout<<"1: "<<sol.lengthOfLongestSubstring(s)<<endl;
	string s2 = "anviaj";
	cout<<"5: "<<sol.lengthOfLongestSubstring(s2)<<endl;
	string s3 = "vqblqcb";
	cout<<"4: "<<sol.lengthOfLongestSubstring(s3)<<endl;
}
