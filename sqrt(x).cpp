#include<bits/stdc++.h>
using namespace std;
int squareroot(int n)
{
	int low=1,high=n;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(mid*mid<=n)
			low=mid+1;
		else
			high=mid-1;
	}
	return high;
}

int main()
{
	int n;
	cin>>n;
	int result=squareroot(n);
	cout<<result;
}

/*
	n=16
	result=4
	
	n=15
	result=3
	
	finds squareroot of n less than or equals to n
	
	T.C : O(logn)
*/
