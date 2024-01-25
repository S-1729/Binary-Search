class Solution{
public:
	int UpperBound(vector<int>arr,int n,int x)
	{
		int low=0,high=n-1,ans=n;
		while(low<=high)
		{
			int mid=low+(high-low)/2;
			if(arr[mid]>x){
				ans=mid;
				high=mid-1;
			}
			else
				low=mid+1;
		}
		return ans;
	}
	
	int countSmallEqual(vector<vector<int>> &matrix, int m, int n,int mid)
	{
	    int count=0;
	    for(int i=0;i<m;i++)
	        count+=UpperBound(matrix[i],n,mid);
	    return count;
	}
	
	int median(vector<vector<int>> &matrix, int m, int n) {
	    int low=INT_MAX,high=INT_MIN;
	    for(int i=0;i<m;i++){
	        low=min(low,matrix[i][0]);
	        high=max(high,matrix[i][n-1]);
	    }
	
	    while(low<=high){
	        int mid=low+(high-low)/2;
	        int smallEqual=countSmallEqual(matrix,m,n,mid);
	        if( smallEqual<=((m*n)/2) )
	            low=mid+1;
	        else
	            high=mid-1;
	    }
	    return low;
	
	}
};

/*
	You are given a row-wise sorted matrix 'mat' of size m x n where 'm' and 'n' are the numbers of rows and columns of the matrix, respectively.
	Your task is to find and return the median of the matrix.
	Note: 'm' and 'n' will always be odd.
	
	Example:
	Input: 'n' = 5, 'm' = 5
	'mat' = 
	[   [ 1, 5, 7, 9, 11 ],
    	[ 2, 3, 4, 8, 9 ],
    	[ 4, 11, 14, 19, 20 ],
    	[ 6, 10, 22, 99, 100 ],
    	[ 7, 15, 17, 24, 28 ]   ]

	Output: 10
	Explanation: If we arrange the elements of the matrix in the sorted order in an array, they will be like this-
	1 2 3 4 4 5 6 7 7 8 9 9 10 11 11 14 15 17 19 20 22 24 28 99 100 
	So the median is 10, which is at index 12, which is midway as the total elements are 25, so the 12th index is exactly midway. Therefore, the answer will be 10. 
	
	T.C : log(1e9)*m*log(n)
*/
