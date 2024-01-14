#include<bits/stdc++.h>
using namespace std;
bool SearchRotatedArray_II(int arr[],int n,int x)
{
	int low=0,high=n-1;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(arr[mid]==x)
			return true;
		else if(arr[low]==arr[mid] && arr[mid]==arr[high])
			low++,high--;
		else if(arr[low]<=arr[mid])
		{
			if(arr[low]<=x && x<=arr[mid])
				high=mid-1;
			else
				low=mid+1;
		}
		else
		{
			if(arr[mid]<=x && x<=arr[high])
				low=mid+1;
			else
				high=mid-1;	
		}
	}
	return false;
}
int main()
{
	int n,x;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>x;
	
	bool result=SearchRotatedArray_II(arr,n,x);
	cout<<result;
	
}

/*
	case-I:
	arr[7]= 3 4 5 7 1 2 3 //duplicates
	x=1
	result=true
	
	case-II:
	arr[7]=3 1 2 3 3 3 3 
	x=1
	result=true
	
	Searches for the element exits or not in a rotated sorted array with duplicates
	 
	T.C : O(logn)
*/
