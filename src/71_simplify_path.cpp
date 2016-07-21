#include<iostream>
#include<string>
#include<vector>
using namespace::std;

class Solution {
public:
	string simplifyPath(string path) {
		path.push_back('/');
		string res="";
		vector<string> subPath;
		if(path.size()<1) return res;
		int numOfDot = 0;
		int l = 0;
		for(int i=1;i<path.size();i++)
		{
			if(path[i]=='/')
			{
				if(numOfDot==1&&l==1);
				else if(numOfDot==2&&l==2)
				{
					if(subPath.size()>0)
					{
						subPath.pop_back();
					}
				}
				else
				{
					if(l>0)
						subPath.push_back(path.substr(i-l,l));
				}
				numOfDot = 0;
				l = 0;
			}
			else if(path[i]=='.')
			{
				l++;
				numOfDot++;
			}
			else
				l++;
		}
		for(int i=0;i<subPath.size();i++)
			res += "/"+subPath[i];
		return res==""?"/":res;
	}
};

int main(){
	Solution sol;
	string path1 = "/a/./b/../../c/";
	string path2 = "/home/";
	string path3 = "/../";
	string path4 = "/home//foo/";
	string path5 = "/...";
	string path6 = "/..hidden";
	cout<<sol.simplifyPath(path1)<<endl;
	cout<<sol.simplifyPath(path2)<<endl;
	cout<<sol.simplifyPath(path3)<<endl;
	cout<<sol.simplifyPath(path4)<<endl;
	cout<<sol.simplifyPath(path5)<<endl;
	cout<<sol.simplifyPath(path6)<<endl;
	cout<<"\n========answer========"<<endl;
	cout<<"/c\n/home\n/\n/home/foo\n/...\n/..hidden"<<endl;
}
