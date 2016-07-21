#include<iostream>
#include<string>
using namespace::std;


class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        string tmp;
        for(int i=0;i<n-1;i++)
        {
			tmp.clear();
			char value = -1;
			int repeat = 0;
            for(int j=0;j<res.size();j++)
            {
                if(res[j]==value)
                {
                    repeat++;
                }
                else
                {
                    if(value!=-1)
                    {
                        tmp+=(char)(repeat+'1');
                        tmp+=value;
                    }
                    value = res[j];
                    repeat = 0;
                }
            }
            if(value!=-1)
            {
                tmp+=(char)(repeat+'1');
                tmp+=value;
            }
            res = tmp;
        }
        return res;
    }
};

int main(){
	Solution sol;
	for(int i=1;i<5;i++)
	{
		string res = sol.countAndSay(i);
		cout<<res<<endl;	
	}

}
