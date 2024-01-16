#include<bits/stdc++.h>
using namespace std;
bool isPerfectSquare(int n)
{
	int low=1,high=n;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(mid*mid==n)
			return true;
		else if(mid*mid<n)
			low=mid+1;
		else
			high=mid-1;
	}
	return false;
}

int main()
{
	int n;
	cin>>n;
	bool result=isPerfectSquare(n);
	cout<<result;
}

/*
	n=16
	result=true
	
	n=15
	result=false
	
	finds the number is perfect square or not
	
	T.C : O(logn)
*/
