class Solution {
public:
    int maxElement(vector<vector<int>>& mat,int n,int m,int col)
    {
        int maxm=INT_MIN,ind=0;
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxm){
                maxm=mat[i][col];
                ind=i;
            }
        }
        return ind;
    }
    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int ind=maxElement(mat,n,m,mid);
            int left=mid!=0?mat[ind][mid-1]:-1;
            int right=mid!=m-1?mat[ind][mid+1]:-1;
            if(mat[ind][mid]>left && mat[ind][mid]>right)
                return {ind ,mid};
            else if(mat[ind][mid]<left)
                high=mid-1;
            else
                low=mid+1;
        }
        return {};
    }
};

/*
	A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
	Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
	You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
	
	Input: mat = [[1,4],[3,2]]
	Output: [0,1]
	Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.

	T.C : O(n*logm)
*/
