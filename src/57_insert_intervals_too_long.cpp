#include<iostream>
#include<vector>
#include<map>
using namespace::std;
/**
 * Definition for an interval.
 */
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
class Solution {
public: 
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        if(intervals.empty())
        {
            res.push_back(newInterval);
            return res;
        }
		//push intervals which is prior to newInterval
		int merge = 0; //0 no merge, 1 need to merge, 2 merged
		for(int i=0;i<intervals.size();i++)
		{
			if(newInterval.start>intervals[i].end || newInterval.end<intervals[i].start)
			{
				if(merge==1 || newInterval.end<intervals[i].start&&merge==0)
				{
					res.push_back(newInterval);	
					res.push_back(intervals[i]);
					merge = 2;
				}
				else
					res.push_back(intervals[i]);
			}
			else
			{
				merge = 1;
				newInterval.start = intervals[i].start<newInterval.start?intervals[i].start:newInterval.start;
				newInterval.end = intervals[i].end > newInterval.end ? intervals[i].end:newInterval.end;
			}
		}
		if(merge!=2)
			res.push_back(newInterval);
		return res;
	}
};

int main(){
	Solution sol;
	Interval in1(1,3);
	Interval in2(5,7);
	Interval in3(12,14);
	Interval in4(15,18);
	vector<Interval> intervals;
	intervals.push_back(in1);
	intervals.push_back(in2);
	intervals.push_back(in3);
	intervals.push_back(in4);
	vector<Interval> res = sol.insert(intervals,Interval(0,0));
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i].start<<" "<<res[i].end<<endl;
	}
}
