#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int>::iterator it1 = nums1.begin();
		vector<int>::iterator it2 = nums2.begin();
		int i=0,j=0;
		while(i<m && j<n)
		{
			if(*it1>=*it2)
			{
				it1 = nums1.insert(it1,*it2++);
				it1++;
				j++;
			}
			else
			{
				it1++;	
				i++;
			}
		}
		while(j<n)
		{
			it1 = nums1.insert(it1,*it2++);
			it1++;
			j++;
		}
		nums1.resize(m+n);
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
