#include<iostream>
#include<vector>
#include<string>
using namespace::std;

class Solution {
public:
	void completeTheLine(int index,vector<string>& words, int maxWidth, int wordCount, int curWordLength, string& str){
		int TotalSpace = maxWidth-curWordLength;
		int evenS = wordCount>1?TotalSpace/(wordCount-1):TotalSpace;
		int addiS = wordCount>1?TotalSpace%(wordCount-1):0;
		for(int i=0;i<wordCount;i++)
		{
			str+=words[index++];
			//last word no space if there are more than one word
			if(i==wordCount-1 && wordCount!=1) continue;
			for(int j=0;j<evenS;j++)
				str.push_back(' ');
			if(addiS)
			{
				str.push_back(' ');
				addiS--;
			}
		}
		return;
	}
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> res;
		string str="";
		int wordCount=0;
		int curWordLength=0;

		for(int i=0;i<words.size();i++)
		{
			//this line is full
			if(curWordLength+wordCount+words[i].size()>maxWidth){
				completeTheLine(i-wordCount,words,maxWidth,wordCount,curWordLength,str);

				res.push_back(str);
				str.clear();
				wordCount=0;
				curWordLength=0;
			}
			//current line
			wordCount++;
			curWordLength += words[i].size();
		}
		//Last line
		
		for(int i=words.size()-wordCount;i<words.size();i++)
		{
			str+=words[i];
			if(str.size()<maxWidth)
				str.push_back(' ');
		}
		while(str.size()<maxWidth) str.push_back(' ');
		res.push_back(str);
		str.clear();
		return res;
    }
};

int main(){
	Solution sol;
	string arr[] = {"This", "is", "an", "example", "of", "text", "justification."};
	int maxWidth = 0;
	vector<string> words(arr,arr+sizeof(arr)/sizeof(string));
	vector<string> res = sol.fullJustify(words,maxWidth);

	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}

}
