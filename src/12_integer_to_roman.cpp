#include<iostream>
#include<string.h>
using namespace::std;
class Solution {
public:
    string getRomanCharacter(int head,int tail,int digit){
		if(!head&&!tail)
			return '\0';
		char character[7] = {'I','V','X','L','C','D','M'};
		string result;
		result+=character[head/5+2*(digit-1)];
		if(tail>=0)
			for(int i=0;i<tail;i++)
				result+=character[2*(digit-1)];	
		else
			result = character[2*(digit-1)]+result;
		return result;

	} 
    string intToRoman(int num) {
		string result;	
        for(int i=1000,j=4;i>0;i/=10,j--){
			int digit = (num/i)%10;
			if(digit==0){
				continue;
			}
			else if(digit<4){
				result+=getRomanCharacter(1,digit-1,j);
			}	
			else if(digit<9){
				result+=getRomanCharacter(5,digit-5,j);
			}else{
				result+=getRomanCharacter(10,digit-10,j);
			}	
		}
		return result;
    }
};
int main(){
	int num=100;
	cout<<"Enter number to convert: "<<endl;
	cin>>num;
	Solution sol;
	cout<<sol.intToRoman(num)<<endl;

	return 0;
}
