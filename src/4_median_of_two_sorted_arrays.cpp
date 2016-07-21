#include<iostream>
#include<map>
using namespace::std;
class Solution {
public:
	double findKelement(int A[],int m, int B[], int n, int k)//1~k
	{
		if(m==0) return B[k-1];
		else if(n==0) return A[k-1];
		else if(k==1) return A[0]>B[0]?B[0]:A[0];
		
		int disM=0,disN=0;	
		if(((m+1)/2+(n+1)/2)<=k)
		{
			if(A[(m-1)/2] <= B[(n-1)/2])
				disM = (m+1)/2;
			if(A[(m-1)/2] >= B[(n-1)/2])
				disN = (n+1)/2;
			return findKelement(A+disM,m-disM,B+disN,n-disN,k-disM-disN);
		}
		else if(((m+1)/2+(n+1)/2)>k)
		{
			if(A[(m-1)/2] <= B[(n-1)/2])
				disN = (n+1)/2;
			if(A[(m-1)/2] >= B[(n-1)/2])
				disM = (m+1)/2;
			return findKelement(A,m-disM,B,n-disN,k);
		}
	}
	double findMedianSortedArrays(int A[], int m, int B[], int n) 
	{
		if((m+n)%2 == 0)
			return (findKelement(A,m,B,n,(m+n)/2)+findKelement(A,m,B,n,(m+n)/2+1))/2;
		else
			return findKelement(A,m,B,n,(m+n+1)/2);
	}
};

int main()
{
	int A[6] = {0,2,4,6,8,10};
	int B[7] = {1,3,5,7,9,11,13};
	Solution s;
	cout<<"Sould be 6: "<<s.findMedianSortedArrays(A,6,B,7)<<endl;
	int C[3] = {1,1,1};
	int D[3] = {1,1,1};
	cout<<"Sould be 1: "<<s.findMedianSortedArrays(C,3,D,3)<<endl;
	int E[1] = {3};
	int F[3] = {1,2,4};
	cout<<"Sould be 2.5: "<<s.findMedianSortedArrays(E,1,F,3)<<endl;
	int G[1] = {0};
	int H[1] = {1};
	cout<<"Sould be 1: "<<s.findMedianSortedArrays(G,0,H,1)<<endl;
	int I[2] = {1,2};
	int J[3] = {3,4,5};	
	cout<<"Sould be 3: "<<s.findMedianSortedArrays(I,2,J,3)<<endl;
	int K[2] = {4,5};
	int L[3] = {1,2,3};	
	cout<<"Sould be 3: "<<s.findMedianSortedArrays(K,2,L,3)<<endl;
	int M[1] = {1};
	int N[4] = {2,3,4,5};	
	cout<<"Sould be 3: "<<s.findMedianSortedArrays(M,1,N,4)<<endl;
	int O[2] = {5,6};
	int P[4] = {1,2,3,4};
	cout<<"Sould be 3.5: "<<s.findMedianSortedArrays(O,2,P,4)<<endl;
	int Q[3] = {1,2,3};
	int R[4] = {4,5,6,7};
	cout<<"Sould be 4: "<<s.findMedianSortedArrays(Q,3,R,4)<<endl;
}
