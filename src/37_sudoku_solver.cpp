#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
	bool check(vector<vector<char> >&board,int cel_num,char fill){
		int row = cel_num/9;
		int col = cel_num%9;
		for(int i=0;i<9;i++)
		{
			if(board[i][col]==fill) return false;
			if(board[row][i]==fill) return false;
		}
		for(int i=row/3*3;i<row/3*3+3;i++)
		{
			for(int j=col/3*3;j<col/3*3+3;j++)
			{
				if(board[i][j]==fill) return false;
			}
		}
		return true;
	}
	bool dfs(vector<vector<char> >& board,int cel_num){
		int row = cel_num/9;
		int col = cel_num%9;
		while(cel_num<81 && board[row][col]!='.')
		{
			cel_num++;
			row = cel_num/9;
			col = cel_num%9;
		}
		if(cel_num==81) return true;
		for(int i=0;i<9;i++)
		{
			if(check(board,cel_num,(char)(i+'1')))
			{
				board[row][col] = (char)(i+'1');
				if(dfs(board,cel_num)) return true;
			}
		}
		board[row][col]='.';
		return false;
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
