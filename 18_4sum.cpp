#include<iostream>
#include<algorithm>
#include<vector>
using namespace::std;
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        sort(num.begin(),num.end());
        for(int i=0;i<num.size();i++){
            for(int j=i+1;j<num.size();j++){
                int front = j+1;
                int rear = num.size()-1;
                while(front<rear){
                    int sum = num[i]+num[j]+num[front]+num[rear];
                    if(sum==target){
                        vector<int> oneR;
                        oneR.push_back(num[i]);
                        oneR.push_back(num[j]);
                        oneR.push_back(num[front]);
                        oneR.push_back(num[rear]);
                        res.push_back(oneR);
						while(num[front]==num[front+1]){
							front++;
						}
						while(num[rear]==num[rear-1]){
							rear--;
						}
						front++;
						rear--;
                    }
                    else if(sum<target){
                        front++;
                    }
                    else{
                        rear--;
                    }
                
                }
                while(num[j]==num[j+1]&&j<num.size()){
                    j++;
                }
            }
            while(num[i]==num[i+1]&&i<num.size()){
                i++;
            }
        }
        return res;
    }
};

int main(){
	Solution sol;
	int array[7] =	{-1,2,2,-5,0,-1,4};
	int target = 3;
	vector<int> num(array,array+7);
	vector<vector<int> > res = sol.fourSum(num,target);
	
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}

}
