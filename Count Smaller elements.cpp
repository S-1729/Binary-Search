class Solution {
  public:
    int binarySearch(vector<int> &v,int x){
        int low=0,high=v.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(v[mid]>=x)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }

    vector<int> constructLowerArray(vector<int> &arr) {
        int n=arr.size();
        vector<int>v,ans(n,0);
        for(int i=n-2;i>=0;i--){
            int ind=binarySearch(v,arr[i]);
            ans[i]=ind;
            v.insert(v.begin()+ind,arr[i]);
        }
        return ans;
    }
};

/*
    Given an array arr containing non-negative integers. Count and return an array ans where ans[i] denotes the number of smaller elements on right side of arr[i].
    
    Examples:
    
    Input: arr[] = [12, 1, 2, 3, 0, 11, 4]
    Output: [6, 1, 1, 1, 0, 1, 0]
    Explanation: There are 6 smaller elements right after 12. There is 1 smaller element right after 1. And so on.
    
    Input: arr[] = [1, 2, 3, 4, 5]
    Output: [0, 0, 0, 0, 0]
    Explanation: There are 0 smaller elements right after 1. There are 0 smaller elements right after 2. And so on.
    
    T.C : O(nlogn)
*/
