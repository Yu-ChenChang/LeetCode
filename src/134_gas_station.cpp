#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		int curgas = 0, netgas = 0, start = 0;
		for(int i=0;i<n;i++)
		{
			netgas += gas[i]-cost[i];
			curgas += gas[i]-cost[i];
			if(curgas<0){
				curgas = 0;
				start = i+1;
			}
		}
		return (netgas<0)?-1:start;
	}
};

int main(){

}
