#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace::std;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > result;
		sort(num.begin(),num.end());
		for(int i=0;i<num.size();i++){
			int front = i+1;
			int rear = num.size()-1;	
			int target = -num[i];
			while(front<rear){
				if(num[front]+num[rear]>target){
					rear--;
				}
				else if(num[front]+num[rear]<target){
					front++;
				}
				else{
					vector<int> oneR;
					oneR.push_back(num[i]);
					oneR.push_back(num[front]);
					oneR.push_back(num[rear]);
					result.push_back(oneR);	
					while(num[front]==num[front+1]&&front<rear)
						front++;
					while(num[rear]==num[rear+1]&&front<rear)
						rear--;
					front++;
				}
			}
			while(num[i]==num[i+1]&&i<num.size())
				i++;
		}
		return result;	
		
    }
};
int main(){
	int array[6] = {-1,0,1,2,-1,-4};
	vector<int> num(array,array+6);
	Solution sol;
	vector<vector<int> >result = sol.threeSum(num);
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}


}
