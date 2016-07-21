#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
		//verfier
		int square[9][9]={0};
		int row[9][9]={0};
		int col[9][9]={0};
		
		for(int row_Index=0;row_Index<board.size();row_Index++)
		{
			for(int col_Index=0;col_Index<board[row_Index].size();col_Index++)
			{
				int value = (int)board[row_Index][col_Index]-49;
				if(value<0||value>8) continue;
				if(!row[row_Index][value]) row[row_Index][value]=1;
				else return false;
				if(!col[col_Index][value]) col[col_Index][value]=1;
				else return false;
				if(!square[row_Index/3*3+col_Index/3][value]) square[row_Index/3*3+col_Index/3][value]=1;
				else return false;
			}

		}
		return true;
    }
};


int main(){
	char c = '1';
	int v = (int)c-49;
	cout<<v<<endl;
}
