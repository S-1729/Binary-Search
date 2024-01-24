class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int low=0,high=m*n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=mid/m,col=mid%m;
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
};

/*
	You are given an m x n integer matrix matrix with the following two properties:
		1.Each row is sorted in non-decreasing order.
		2.The first integer of each row is greater than the last integer of the previous row.
	Given an integer target, return true if target is in matrix or false otherwise.
	You must write a solution in O(log(m * n)) time complexity.
	
	Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
	Output: true
	
	T.C : O(log(m*n)
*/
