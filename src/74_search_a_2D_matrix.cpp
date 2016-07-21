#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
		if(matrix.empty()) return false;        
		int selectR = matrix.size()-1;
		if(matrix[0][0]>target) return false;
		for(int row=1;row<matrix.size();row++)
			if(matrix[row][0]>target)
			{
				selectR = row-1;
				break;
			}
		//binary search the row	
		int begin=0,end=matrix[selectR].size()-1;
		while(begin<=end)
		{
			int mid = (begin+end)/2;
			if(matrix[selectR][mid]<target)
				begin = mid+1;
			else if(matrix[selectR][mid]>target)
				end = mid-1;
			else
				return true;
		}
		return false;
    }
};

int main(){
	Solution sol;
	int arr[] = {1,3};
	vector<int> vec(arr,arr+sizeof(arr)/sizeof(int));
	int arr2[] = {25};
	vector<int> vec2(arr2,arr2+sizeof(arr2)/sizeof(int));
	vector<vector<int> > matrix;
	matrix.push_back(vec);	
	matrix.push_back(vec2);
	cout<<sol.searchMatrix(matrix,3)<<endl;

}
