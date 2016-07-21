#include<iostream>
#include<vector>
#include<string>
using namespace::std;

class Solution {
public:
		void printB(vector<string>& board){
			for(int row=0;row<board.size();row++)
			{
				for(int col=0;col<board[row].size();col++)
					cout<<board[row][col]<<" ";
				cout<<endl;
			}
			cout<<endl;
		}
		bool validDiagonal(int row, int col,int n, vector<string>& board){
			bool res = true;
			for(int i=0;i<n;i++)
			{
				if(row-i>=0)
				{
					if(col-i>=0)
					{
						if(board[row-i][col-i]=='Q') return false;
					}
					if(col+i<n)
					{
						if(board[row-i][col+i]=='Q') return false;
					}
				}
				if(row+i<n)
				{
					if(col-i>=0)
					{
						if(board[row+i][col-i]=='Q') return false;
					}
					if(col+i<n)
					{
						if(board[row+i][col+i]=='Q') return false;
					}
				}
			}
			return true;

		}
		void backTracking(int curRow, vector<int> pCol, int n, 
									int& res, vector<string>& board){
		if(curRow == n)
		{
			res++;
			return;
		}

		for(int col=0;col<n;col++)
		{
			if(pCol[col])
			{
				if(validDiagonal(curRow,col,n,board))
				{
					board[curRow][col] = 'Q';
					pCol[col] = 0;
					backTracking(curRow+1,pCol,n,res,board);
					board[curRow][col] = '.';
					pCol[col] = 1;
				}
			}
		}
		return;
	}

    int totalNQueens(int n) {
		int res=0;
		vector<string> board;
		string row;
		//Initialize board
		for(int i=0;i<n;i++)
			row +='.';
		for(int i=0;i<n;i++)
			board.push_back(row);
		vector<int> pCol;
		for(int i=0;i<n;i++)
			pCol.push_back(1);
		//BackTracking Answer
		backTracking(0,pCol,n,res,board);
		return res;
    }
};

int main(){
	Solution sol;
	int res = sol.totalNQueens(1);
	cout<<res<<endl;
	return 0;
}
