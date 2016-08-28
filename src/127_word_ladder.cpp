#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<array>
using namespace::std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		if(wordList.empty()) return 0;
		queue<string> bfsQueue;
		queue<int> disQueue;
		int n = beginWord.size();
		bfsQueue.push(beginWord);
		disQueue.push(2);
		while(!bfsQueue.empty())
		{
			int dis = disQueue.front();
			disQueue.pop();
			string cur = bfsQueue.front();
			bfsQueue.pop();
			for(int i=0;i<n;i++)
			{
				char tmp = cur[i];
				for(char c='a';c<='z';c++)
				{
					cur[i] = c;
					if(endWord==cur) return dis;

					unordered_set<string>::iterator it = wordList.find(cur);
					if(it!=wordList.end())
					{
						bfsQueue.push(*it);
						disQueue.push(dis+1);
						wordList.erase(it);
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
