#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<array>
#include<utility>
using namespace::std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		if(wordList.empty()) return 0;
		queue<pair<string,int> > bfsQueue; //<word,distance>
		int n = beginWord.size();
		bfsQueue.push(pair<string,int>(beginWord,2));
		while(!bfsQueue.empty())
		{
			int dis = bfsQueue.front().second;
			string cur = bfsQueue.front().first;
			bfsQueue.pop();
			for(int i=0;i<n;i++)
			{
				char tmp = cur[i];
				for(char c='a';c<='z';c++)
				{
					cur[i] = c;
					if(endWord==cur) return dis;

					if(wordList.find(cur)!=wordList.end())
					{
						bfsQueue.push(pair<string,int>(cur,dis+1));
						wordList.erase(cur);
					}
				}
				cur[i] = tmp;
			}
		}
		return 0;
	}
};

int main(){
	unordered_set<string> uset; 
	array<string,5> arr = {"hot","dot","dog","lot","log"};
	uset.insert(arr.begin(),arr.end());
	Solution sol;
	cout<<sol.ladderLength("hit","cog",uset)<<endl;

}
