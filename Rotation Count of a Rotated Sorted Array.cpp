#include<bits/stdc++.h>
using namespace std;
int RotationCount(int arr[],int n)
{
	int low=0,high=n-1,ans=INT_MAX,index=-1;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(arr[low]<=arr[high])
		{
			if(arr[low]<ans){
				ans=arr[low];
				index=low;
			}
		}
			ans=min(ans,arr[low]);
		if(arr[low]<=arr[mid])
		{
			if(arr[low]<ans){
				ans=arr[low];
				index=low;
			}
			low=mid+1;
		}
		else
		{
			if(arr[mid]<ans){
				ans=arr[mid];
				index=mid;
			}
			high=mid-1;	
		}
	}
	return index;
}
int main()
{
	int n,x;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	int result=RotationCount(arr,n);
	cout<<result;
	
}

/*
	arr[7]= 4 5 6 7 1 2 3
	result=4     //the rotated 4 times
	
	Searches for the minimum element index in a rotated sorted array which gives rotation count
	
	T.C : O(logn)
*/
