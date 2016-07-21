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
    vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
		if(intervals.empty()) return res;
		map<int,int> omap;
		for(int i=0;i<intervals.size();i++)
		{
			if(omap[intervals[i].start] < intervals[i].end)
				omap[intervals[i].start] = intervals[i].end;
		}
		for(map<int,int>::iterator it=omap.begin();it!=omap.end();it++)
		{
			map<int,int>::iterator move = it;
			for(map<int,int>::iterator it2=it;it2!=omap.end();it2++)
			{
				if(it==it2) continue;
				if(it->second >= it2->first)
				{
					if(it->second < it2->second)
						it->second = it2->second;
					move++;
				}
				else
					break;
			}
			res.push_back(Interval(it->first,it->second));
			it = move;
		}

		return res;
    }
};

int main(){
	Solution sol;
	Interval in1(2,3);
	Interval in2(3,3);
	Interval in3(1,3);
	Interval in4(15,18);
	vector<Interval> intervals;
	intervals.push_back(in1);
	intervals.push_back(in2);
	intervals.push_back(in3);
	intervals.push_back(in4);
	vector<Interval> res = sol.merge(intervals);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i].start<<" "<<res[i].end<<endl;
	}
}
