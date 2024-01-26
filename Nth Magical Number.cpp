class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long low=min(a,b),mod=1000000007;
        long long high=1LL*min(a,b)*n;
        
        long long A=a,B=b;
        while(B!=0){
            int temp=A;
            A=B;
            B=temp%B;
        }
        long long lcm=(1LL*a*b)/A;
        
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long count=mid/a+mid/b-mid/lcm;
            if(count<n)
                low=mid+1;
            else
                high=mid-1;
        }
        return low%mod;
    }
};

/*
	A positive integer is magical if it is divisible by either a or b.
	Given the three integers n, a, and b, return the nth magical number. 
	Since the answer may be very large, return it modulo 109 + 7.
	
	Example 1:
	Input: n = 1, a = 2, b = 3
	Output: 2
	
	Example 2:
	Input: n = 4, a = 2, b = 3
	Output: 6
	
	T.C : O(log(n*min(a,b))
*/
