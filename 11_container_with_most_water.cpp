#include<vector>
#include<iostream>
using namespace::std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max=0;
        int l=0,r=height.size()-1;
        while(l<r)
        {
            int minH = height[l]>height[r]?height[r]:height[l];
            int water = minH * (r-l);
            max = water>max?water:max;
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
        return max;
    }
};
int main(){


}
