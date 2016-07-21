#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
	bool search(int i, vector<vector<char> >& board, string word, int windex){
		if(windex== word.size()) return true;
		int row = board.size(),col=board[0].size();
		int value = board[i/col][i%col];
		board[i/col][i%col] = 0;
		//up
		if(i/col>0 && board[i/col-1][i%col]==word[windex]) 
			if(search(i-col,board,word,windex+1)) return true;
		//down
		if(i/col<row-1 && board[i/col+1][i%col]==word[windex])
			if(search(i+col,board,word,windex+1)) return true;
		//left
		if(i%col>0 && board[i/col][i%col-1]==word[windex])
			if(search(i-1,board,word,windex+1)) return true;
		//right
		if(i%col<col-1 && board[i/col][i%col+1]==word[windex])
			if(search(i+1,board,word,windex+1)) return true;
		board[i/col][i%col] = value;
		return false;
	}
    bool exist(vector<vector<char> >& board, string word) {
		if(board.empty()) return word=="";
		int row = board.size(),col = board[0].size();
		for(int i=0;i<row*col;i++)
		{
			if(word[0]==board[i/col][i%col])
			{
				if(search(i,board,word,1)) return true;
			}
		}
		return false;
    }
};

int main(){
	Solution sol;
	vector<vector<char> > board;
	char arr[] = {'A','B','C','E'};
	char arr2[] = {'S','F','E','S'};
	char arr3[] = {'A','D','E','E'};
	board.push_back(vector<char>(arr,arr+sizeof(arr)/sizeof(char)));
	board.push_back(vector<char>(arr2,arr2+sizeof(arr2)/sizeof(char)));
	board.push_back(vector<char>(arr3,arr3+sizeof(arr3)/sizeof(char)));
	cout<<sol.exist(board,"ABCCED")<<endl;
	cout<<sol.exist(board, "ABCESEEEFS")<<endl;
	//char arr[] = {'A','A'};
	//board.push_back(vector<char>(arr,arr+sizeof(arr)/sizeof(char)));
	cout<<sol.exist(board,"AAA")<<endl;

}
