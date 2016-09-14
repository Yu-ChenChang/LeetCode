#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace::std;

/**
 * Definition for a point.
 **/
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
		if(points.size()<3) return points.size();
		int res = 0;
		for(int i=0;i<points.size();i++){
			unordered_map<float, int> umap;
			int localres=0, same = 0, vertical = 0;
			for(int j=i+1;j<points.size();j++){
				if(points[i].x==points[j].x){
					if(points[i].y==points[j].y){
						same++;
					}
					else{
						vertical++;
					}
				}
				float slope = (float)(points[i].y-points[j].y)/(float)(points[i].x-points[j].x);
				umap[slope]++;
				localres = max(localres,umap[slope]);
			}
			localres = max(localres,vertical) + same+1;
			res = max(res,localres);
		}
		return res;
    }
};

int main(){

}
