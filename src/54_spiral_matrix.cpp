#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> >& matrix) {
		vector<int> res;
		if(matrix.empty()) return res;
		int startR = 0,startC = 0;
		int endR = matrix.size()-1;
		int endC = matrix[0].size()-1;
		while(startR<=endR && startC<=endC)
		{
			//right
			for(int col=startC;col<=endC;col++)
				res.push_back(matrix[startR][col]);
			startR++;
			//down
			for(int row=startR;row<=endR;row++)
				res.push_back(matrix[row][endC]);
			endC--;
			//left
			if(startR<=endR)//do not go left if no go down
			{
				for(int col=endC;col>=startC;col--)
					res.push_back(matrix[endR][col]);
				endR--;
			}
			//up
			if(startC<=endC)//do not go up if no go right
			{
				for(int row = endR;row>=startR;row--)
					res.push_back(matrix[row][startC]);
				startC++;
			}
		}
		return res;
	}
};

int main(){
	Solution sol;
	int arr[] = {2,3};
	vector<int> vec(arr,arr+sizeof(arr)/sizeof(int));
	/*j
	int arr2[] = {4,5,6};
	vector<int> vec2(arr2,arr2+sizeof(arr2)/sizeof(int));
	int arr3[] = {7,8,9};
	vector<int> vec3(arr3,arr3+sizeof(arr3)/sizeof(int));
	*/
	vector<vector<int> >matrix;
	matrix.push_back(vec);
	//matrix.push_back(vec2);
	//matrix.push_back(vec3);
	vector<int> res = sol.spiralOrder(matrix);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl;
}
