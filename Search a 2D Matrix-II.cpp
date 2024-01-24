class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int row=0,col=m-1;
        while(row<n && col>=0){
            int ele=matrix[row][col];
            if(ele==target)
                return true;
            else if(target<ele)
                col-=1;
            else
                row+=1;
        }
        return false;
    }
};

/*
	Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
		1.Integers in each row are sorted in ascending from left to right.
		2.Integers in each column are sorted in ascending from top to bottom.
	
	Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
	Output: true
	
	T.C : O(n+m)
	
*/
