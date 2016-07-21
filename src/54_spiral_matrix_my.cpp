#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
		vector<int> res;
		int rowMax = matrix.size();   //row boundary
		int rowMin = 1;
		int colMax = matrix[0].size();//col boundary
		int colMin = 0;
		int state = 0; //'0' go right, '1' go down, '2' go left, '3' go up
		int row = 0;
		int col = 0;
		for(int i=0;i<matrix.size() * matrix[0].size();i++)
		{
			res.push_back(matrix[row][col]);
			for(int twice=0;twice<2;twice++)
			{
				if(state==0)
				{
					if(col+1<colMax)
					{
						col++;
						break;
					}
					else
					{
						colMax--;
						state++;
					}
				}
				else if(state==1)
				{
					if(row+1<rowMax)
					{
						row++;
						break;
					}
					else
					{
						rowMax--;
						state++;
					}
				}
				else if(state==2)
				{
					if(col-1>=colMin)
					{
						col--;
						break;
					}
					else
					{
						colMin++;
						state++;
					}
				}
				else if(state==3)
				{
					if(row-1>=rowMin)
					{
						row--;
						break;
					}
					else
					{
						rowMin++;
						state=0;
					}
				}
				else
					cerr<<"Error Occur!"<<endl;
			}
			
		}
		return res;
    }
};

int main(){
	Solution sol;
	int arr[] = {1,2,3};
	vector<int> vec(arr,arr+sizeof(arr)/sizeof(int));
	int arr2[] = {4,5,6};
	vector<int> vec2(arr2,arr2+sizeof(arr2)/sizeof(int));
	int arr3[] = {7,8,9};
	vector<int> vec3(arr3,arr3+sizeof(arr3)/sizeof(int));
	vector<vector<int> >matrix;
	matrix.push_back(vec);
	matrix.push_back(vec2);
	matrix.push_back(vec3);
	vector<int> res = sol.spiralOrder(matrix);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl;
}
