#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
	void round_to_O(vector<vector<char> >& board,int i,int j) {
		board[i][j] = 'O';
		if(i>0 && board[i-1][j]=='-') round_to_O(board,i-1,j);
		if(j>0 && board[i][j-1]=='-') round_to_O(board,i,j-1);
		if(j<board[0].size()-1 && board[i][j+1]=='-') round_to_O(board,i,j+1);
		if(i<board.size()-1 && board[i+1][j]=='-') round_to_O(board,i+1,j);
	}
    void solve(vector<vector<char> >& board) {
		if(board.empty()) return;
		int row = board.size();
		int col = board[0].size();
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				if(board[i][j]=='O')
				{
					if(i>0&&i<row-1&&j>0&&j<col-1) //O that is not at boundary
					{
						if(board[i-1][j]!='O' && board[i][j-1]!='O')
							board[i][j] = '-';
						else
						{
							if(board[i-1][j]=='-') round_to_O(board,i-1,j);
							if(board[i][j-1]=='-') round_to_O(board,i,j-1);
						}
					}
					else round_to_O(board,i,j);
				}
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				if(board[i][j]=='-')
					board[i][j] = 'X';
    }
};

int main(){

}
