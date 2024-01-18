#include<bits/stdc++.h>
using namespace std;
int SearchSingleElement(int arr[],int n)
{
	if(n==1)
		return arr[0];
	if(arr[0]!=arr[1])
		return arr[0];
	if(arr[n-1]!=arr[n-2])
		return arr[n-1];
	int low=1,high=n-2;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])
			return arr[mid];
		else if((mid%2==1 && arr[mid]==arr[mid-1])||(mid%2==0 && arr[mid]==arr[mid+1]))
			low=mid+1;
		else
			high=mid-1;	
	}
	return -1;
}

int main()
{
	int n,x;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	int result=SearchSingleElement(arr,n);
	cout<<result;
	
}

/*
	arr[11]= 1 1  2 2  3 3 4 5 5  6 6
	indices=(e o)(e o)(e o)e(o e)(o e)
	result=4
	
	single element always appears on even(e) index
	if mid is on pair(even ,odd)--->element appears on right side
	if mid is on pair(odd ,even)--->element appears on left side
	
	Searches for the single element in a sorted array where every element appears twice except one
	
	T.C : O(logn)
*/
