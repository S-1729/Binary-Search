class Solution{
public:
	int calcStudents(vector<int>&pages,int mid)
	{
		int sum=0,c=1;
		for(auto i:pages){
			sum+=i;
			if(sum>mid){
				c++;
				sum=i;
			}
		}
		return c;
	}
	
	int findPages(vector<int> &pages, int n, int m)
	{
		if(m>n) return -1;
		int low=*max_element(pages.begin(),pages.end());
		int high=accumulate(pages.begin(),pages.end(),0);
		while(low<=high){
			int mid=low+(high-low)/2;
			int students=calcStudents(pages,mid);
			if(students<=m)
				high=mid-1;
			else
				low=mid+1;
		}
		return low;
	}
};

/*
	You have n books, each with pages[i] number of pages. m students need to be allocated contiguous books, with each student getting at least one book.
	Out of all the permutations, the goal is to find the permutation where the sum of maximum number of pages in a book allotted to a student should be minimum, out of all possible permutations.
	Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).
	
	Input:
	n = 4
	pages[] = {12,34,67,90}
	m = 2
	
	Output:113
	
	Explanation:Allocation can be done in 
	following ways:
	{12} and {34, 67, 90} Maximum Pages = 191
	{12, 34} and {67, 90} Maximum Pages = 157
	{12, 34, 67} and {90} Maximum Pages =113.
	Therefore, the minimum of these cases is 113,
	which is selected as the output.
	
	T.C: O(n*logn)
*/
