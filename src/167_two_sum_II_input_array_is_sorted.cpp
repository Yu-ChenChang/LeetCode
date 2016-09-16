#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> res(2,0);
		int left=0,right=numbers.size()-1;
		while(left<right){
			int sum = numbers[left]+numbers[right];
			int mid = (left+right)>>1;
			if(sum<target){ 
				left++;
			}
			else if(sum>target){
				right--;
			}
			else{
				res[0] = left+1;
				res[1] = right+1;
				break;
			}
		}
		return res;
    }
};

int main(){

}
