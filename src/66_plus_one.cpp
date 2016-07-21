#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
		digits[digits.size()-1]++;	
        for(int i=digits.size()-1;i>=0;i--)
        {
			if(carry)
			{
				digits[i]++;
				carry = 0;
			}

			if(digits[i]>=10)
			{
				digits[i]%=10;
				carry = 1;
			}
        }
		if(carry) digits.insert(digits.begin(),1);
		return digits; 
    }
};
int main(){
	Solution sol;
	int arr[] = {9,9,9};
	vector<int> digits(arr,arr+sizeof(arr)/sizeof(int));
	vector<int> res = sol.plusOne(digits);

	for(int i=0;i<res.size();i++)
		cout<<res[i];
	cout<<endl;


}
