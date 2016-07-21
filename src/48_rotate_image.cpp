#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
	void printM(vector<vector<int> >&matrix){
		for(int i=0;i<matrix.size();i++)
		{
			for(int j=0;j<matrix[i].size();j++)
			{
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
		return;
	}
	void nextIndex(int& row,int& col,int size,int level){
		int iter = size-1;
		int flag = 0;
		if(row==0+level) flag = 1;
		else if(col==size-1+level) flag = 2;
		else if(row==size-1+level) flag = 3;
		else if(col==0+level) flag = 4;

		for(;iter>0;iter--)
		{
			switch(flag){
				case 1:
				{
					if(col<size-1+level) col++;
					else row++;
					break;
				}
				case 2:
				{
					if(row<size-1+level) row++;
					else col--;
					break;
				}
				case 3:
				{
					if(col>0+level) col--;
					else row--;
					break;
				}
				case 4:
				{
					if(row>0+level) row--;
					else col++;
					break;
				}
				default:
					cerr<<"Error!"<<endl;
					break;
			}
		}
	}
    void rotate(vector<vector<int> >& matrix) {
		int Msize = matrix[0].size();
		int level =0;
		for(int Csize = Msize;Csize>1;Csize-=2,level++)
		{
			for(int i=0;i<Csize-1;i++)
			{
				int row = 0+level;
				int col = i+level;
				int nextValue = matrix[row][col];
				int curValue = nextValue;
				for(int j=0;j<4;j++)
				{
					nextIndex(row,col,Csize,level);
					nextValue = matrix[row][col];
					matrix[row][col] = curValue;
					curValue = nextValue;
				}
			}
		}
		
    }
};

int main(){
	vector<vector<int> > res;
	int arr[] = {1,2,3,4};
	vector<int> vec1(arr,arr+sizeof(arr)/sizeof(int));// = {1,2};
	int arr2[] = {5,6,7,8};
	vector<int> vec2(arr2,arr2+sizeof(arr2)/sizeof(int));// = {3,4};
	int arr3[] = {9,10,11,12};
	vector<int> vec3(arr3,arr3+sizeof(arr3)/sizeof(int));// = {1,2};
	int arr4[] = {13,14,15,16};
	vector<int> vec4(arr4,arr4+sizeof(arr4)/sizeof(int));// = {1,2};
	res.push_back(vec1);
	res.push_back(vec2);
	res.push_back(vec3);
	res.push_back(vec4);
	Solution sol;

	sol.printM(res);
	sol.rotate(res);
	sol.printM(res);
}
