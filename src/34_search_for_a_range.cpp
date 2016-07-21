#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
	int find_edge(vector<int>& nums,int head,int tail,int target,bool flag)
	{
		if(head==tail)
		{
			if(nums[head]==target) return head;		
			else return -99;
		}
		else if(tail-head == 1)
		{
			if(nums[head]==target && nums[tail]!=target) return head;
			else if(nums[head]!=target && nums[tail]==target) return tail;
			else if(nums[head]==target && nums[tail]==target) return flag?head:tail;
			else return -99;
		}
		else
		{
			int mid = head+(tail-head+1)/2;
			while(nums[mid]!=target)
			{
				if(head>=tail) return -99;
				if(flag) head=mid+1;
				else tail = mid-1;
				mid = head+(tail-head+1)/2;
			}
			if(flag) return find_edge(nums,head,mid,target,flag);
			else return find_edge(nums,mid,tail,target,flag);

		}



	}

    vector<int> searchRange(vector<int>& nums, int target) 
	{
		int arr[] = {-1,-1};
		vector<int> res(arr,arr+2);
		int size = nums.size();
		int head = 0;
		int tail =size-1;
		int mid = size/2;
		while(nums[mid]!=target)
		{
			if(head>=tail) return res;

			if(nums[mid]>target)
			{
				tail = mid-1;	
			}
			else if(nums[mid]<target)
			{
				head = mid+1;
			}

			mid = head+(tail-head+1)/2;
		}
		head = find_edge(nums,head,mid,target,1);
		tail = find_edge(nums,mid,tail,target,0);
		res[0] = head;
		res[1] = tail;
		return res;
    }
};

int main(){
	int array[] = {1,2,2};//{5,7,8,8,8,10};
	vector<int> data(array,array+3);
	int target = 2;
	Solution sol;
	vector<int> res = sol.searchRange(data,target);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
}
