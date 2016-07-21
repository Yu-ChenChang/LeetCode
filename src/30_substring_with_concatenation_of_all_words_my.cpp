#include<iostream>
#include<string.h>
#include<vector>
#include<unordered_map>
using namespace::std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		int wl = words[0].size();
		int wN = words.size();
		if(!wl || !s.size()) return res;

		unordered_map<string,int> wordList;
		for(int i=0;i<wN;i++)
			wordList[words[i]]++;
		unordered_map<string,int> curList; 

		for(int i=0;i<wl;i++)
		{
			int begin = i;
			curList.clear();
			for(int j=i;j<s.size()-wl+1 && begin<s.size()-wl*wN+1;j+=wl)
			{
				if(wordList[s.substr(j,wl)])
				{
					if(curList[s.substr(j,wl)]<wordList[s.substr(j,wl)])
					{
						curList[s.substr(j,wl)]++;
						//find an answer
						if(j-begin == wl*(wN-1))
						{
							res.push_back(begin);
							//recover curList
							curList[s.substr(begin,wl)]--;
							//update begin
							begin += wl;
						}
					}
					else
					{
						//recover curList
						curList[s.substr(begin,wl)]--;
						//update begin
						begin += wl;
						j -= wl;
					}
				}
				else
				{
					//recover curList
					curList.clear();
					//update begin
					begin = j+wl;
				}
				
			}
		}
		return res;		
	}

};


int main(){
	Solution sol;
	string S ="gggoodgoodgoodbest"; 
	string s2= "good";
	string s3= "best";
	vector<string> L;
	//L.push_back(s1);
	L.push_back(s2);
	L.push_back(s2);
	L.push_back(s3);
	vector<int> res = sol.findSubstring(S,L);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
}
