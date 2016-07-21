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

	bool dfs(vector<vector<char> >&board,int row_begin){
		for(int row =row_begin;row<9;row++)
		{
			for(int col=0;col<9;col++)
			{
				if(board[row][col] == '.')
				{
					for(int i=0;i<9;i++)
					{
						board[row][col] = (char)(i+49);
						if(isValidSudoku(board)) 
							if(dfs(board,row)) return true;

					}
					board[row][col] = '.';
					return false;
				}
			}
		}
		return true;
	}

    void solveSudoku(vector<vector<char> >& board) {
		dfs(board,0);	
    }
};

void initialize_vector(vector<vector<char> >&board){
	cout<<"Ex: [\"..9748...\",\"7........\",\".2.1.9...\",\"..7...24.\",\".64.1.59.\",\".98...3..\",\"...8.3.2.\",\"........6\",\"...2759..\"]"<<endl;;
	char input[200];
	cin>>input;
	vector<char> tmp;
	int counter = 2;
 	for(int i=0;i<9;i++)
	{
		tmp.clear();
		for(int j=0;j<9;j++)
		{
			tmp.push_back(input[counter++]);
		}
		counter+=3;
		board.push_back(tmp);
	}


}
void printB(vector<vector<char> >&board){
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			
			if(j==2||j==5)	cout<<board[i][j]<<"|";
			else cout<<board[i][j]<<" ";
		}
		cout<<endl;
		if(i==2||i==5) cout<<"-----------------"<<endl;
	}
	cout<<endl;
}

int main(){
	vector<vector<char> >board;
	initialize_vector(board);
	printB(board);
	Solution sol;
	sol.solveSudoku(board);
	printB(board);
	return 0;
}
