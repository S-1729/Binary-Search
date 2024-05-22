class Solution {
  public:
    int countStations(vector<int> &stations, int n,double mid){
        int c=0;
        for(int i=0;i<n-1;i++){
            int diff=stations[i+1]-stations[i];
            if(diff>mid)
                c+=diff/mid;
        }
        return c;
    }

    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n=stations.size();
        double low=0,high=0;
        for(int i=0;i<n-1;i++)
            high=max(high,(double)(stations[i+1]-stations[i]));
        
        while(high-low>1e-9){
            double mid=low+(high-low)/2.0;
            if(countStations(stations,n,mid)<=k)
                high=mid;
            else
                low=mid;
        }
        return high;
    }
};

/*
    We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where n = size of the stations array. 
    Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 2 decimal places.
    
    Example 1:
    Input:
    n = 10
    stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    k = 9
    Output: 0.50
    Explanation: Each of the 9 stations can be added mid way between all the existing adjacent stations.
    
    Example 2:
    Input:
    n = 10
    stations = [3,6,12,19,33,44,67,72,89,95] 
    k = 2 
    Output: 14.00 
    Explanation: Construction of gas stations at 8th(between 72 and 89) and 6th(between 44 and 67) locations.

    T.C : O(nlogn)
*/
