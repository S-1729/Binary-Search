int findKthPositive(vector<int>& arr, int k) {
    int low=0,high=arr.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int missing=arr[mid]-mid-1;
        if(missing<k)
            low=mid+1;
        else
            high=mid-1;
    }
    return low+k;
}

int main()
{
	int n,k;
	cin>>n>>k;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int result=findKthPositive(arr,k);
	cout<<result;
}

/*
	Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
	Return the kth positive integer that is missing from this array.
	
	Input: arr = [2,3,4,7,11], k = 5
	Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
	
	T.C : O(logn)
*/
