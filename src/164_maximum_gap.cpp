#include<vector>
#include<string>
#include<iostream>
using namespace::std;

struct buc{
	buc(){
		empty = true;
	}
	int max;
	int min;
	bool empty;
};
class Solution {
public:
    int maximumGap(vector<int>& nums) {
		if(nums.size()<2) return 0;
		int mini=nums[0],maxi=nums[0];
		for(int i=0;i<nums.size();i++){
			mini = min(mini,nums[i]);
			maxi = max(maxi,nums[i]);
		}
		int bucketRange = max(1,(maxi-mini-1)/(int)(nums.size()-1)+1);
		int bucketNum = (maxi-mini)/bucketRange+1;
		vector<struct buc> bucket(bucketNum,buc());
		for(int i=0;i<nums.size();i++){
			int loc = (nums[i]-mini)/bucketRange;
			if(bucket[loc].empty){
				bucket[loc].max = nums[i];
				bucket[loc].min = nums[i];
				bucket[loc].empty = false;
			}
			else{
				bucket[loc].max = max(bucket[loc].max,nums[i]);
				bucket[loc].min = min(bucket[loc].min,nums[i]);
			}
		}
		int res = 0;
		int pre = bucket[0].max;
		for(int i=1;i<bucketNum;i++){
			if(bucket[i].empty) continue;
			int gap = bucket[i].min-pre;
			res = max(res,gap);
			pre = bucket[i].max;
		}
		return res;
    }
};

int main(){
	int arr[] = {1, 10000};
	vector<int> vec(arr,arr+sizeof(arr)/sizeof(int));
	Solution sol;
	cout<<sol.maximumGap(vec)<<endl;

}
