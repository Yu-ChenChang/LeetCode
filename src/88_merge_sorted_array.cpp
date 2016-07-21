#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
};


int main(){
	int arr[] = {0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int arr2[] = {1,2,3,5,7};
	vector<int> nums1(arr,arr+sizeof(arr)/sizeof(int));
	vector<int> nums2(arr2,arr2+sizeof(arr2)/sizeof(int));
	Solution sol;
	sol.merge(nums1,1,nums2,1);
	for(int i=0;i<nums1.size();i++)
		cout<<nums1[i]<<" ";
	cout<<endl;
}
