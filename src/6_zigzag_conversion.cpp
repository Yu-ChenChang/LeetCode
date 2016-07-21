#include<iostream>
#include<string>
using namespace::std;

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows == 1) return s;
        int len = s.size();
        //string zigzag[s.size()*(nRows-1)/(nRows+nRows-2)];
        string zigzag;
		int nextBlock = nRows+nRows-2;
		for(int i=0;i<nRows;i++)
			for(int j=0;j<len;j+=nextBlock)
			{
				if(j+i<len)
					zigzag += s[j+i];
				int secondElement = j+nextBlock-i;
				if( secondElement <len && secondElement <j+nextBlock && secondElement > j+i)
					zigzag += s[secondElement];	
			}
		return zigzag;
    }
	string convert_2(string s, int numRows) {
        if(numRows<2) return s;
        string* line = new string[numRows];
        for(int i=0;i<s.size();i++)
        {
            int index = i%(numRows+numRows-2);
            if(index>=numRows) index = numRows-(index-numRows)-2;
            line[index] += s[i];
        }
        string res = "";
        for(int i=0;i<numRows;i++)
            res += line[i];
        return res;
    }
};

int main(int argc,char** argv){
	Solution s;
	string st1= "PAYPALISHIRING";
	string st2= "ABC";
	cout<<s.convert(st1,14)<<endl;
	cout<<s.convert(st2,2)<<endl;
	return 0;


}
