#include<iostream>
#include<string.h>
#include<vector>
#include<unordered_map>
using namespace::std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		int wordLength = words[0].size();
		if(!wordLength) return res;
		unordered_map<string,int> wordList;
		for(int i=0;i<words.size();i++)
		{
			if(!wordList[words[i]])
				wordList[words[i]] = 1;
			else 
				wordList[words[i]]++;
		}
		unordered_map<string,int> curList = wordList;
		for(int i=0;i<s.size()-wordLength*words.size()+1;i++)
		{
			bool flag = true;
			for(int j=0;j<words.size();j++)
			{
				if(curList[s.substr(i+j*wordLength,wordLength)]) curList[s.substr(i+j*wordLength,wordLength)]--;
				else
				{
					flag = false;
					curList = wordList;
					break;
				}
			}
			if(flag)
			{
				curList = wordList;
				res.push_back(i);
			}
		}
		return res;		
	}

};


int main(){
	Solution sol;
	string S ="aaa"; 
	string s2= "a";
	string s3= "a";
	vector<string> L;
	//L.push_back(s1);
	L.push_back(s2);
	L.push_back(s3);
	vector<int> res = sol.findSubstring(S,L);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
}
