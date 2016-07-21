#include<iostream>
#include<deque>
#include<vector>
#include<utility>
using namespace::std;

class monotonicQue{
	public:
		void push(int val){
			int life=0;
			while(!dq.empty()&&dq.back().first<val)
			{
				dq.pop_back();
				life++;
			}
			dq.push_back(pair<int,int>(val,life));
			//need "-std=c++11 -stdlib=libc++ flag" for dq.emplace_back(val,life);
		}
		int max(){
			return dq.front().first;
		}
		void pop_front(){
			if(dq.front().second>0)
				dq.front().second--;
			else
				dq.pop_front();
		}
	private:
		deque<pair<int,int> > dq;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> res;
		monotonicQue mq;
		int i;
		for(i=0;i<k-1;i++)
			mq.push(nums[i]);
			
		for(;i<nums.size();i++)
		{
			mq.push(nums[i]);
			res.push_back(mq.max());
			mq.pop_front();
		}
		return res;
    }
};

int main(){

}
