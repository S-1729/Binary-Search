class Solution {
public:
    int minSteps(int D)
    {
        int low = 1, high=D+2,target=D;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if ((long)mid * (mid + 1) / 2 >= target)
                high = mid-1;
            else
                low = mid + 1;
        }

        if (target % 2 == (int)ceil(low / 2.0) % 2)
            return low;

        return low % 2 == 0 ? low + 1 : low + 2;
    }
};

/*
    Given an infinite number line. You start at 0 and can go either to the left or to the right. The condition is that in the ith move, you must take i steps. Given a destination d, find the minimum number of steps required to reach that destination.

    Example 1:
    Input: d = 2
    Output: 3
    Explaination: The steps takn are +1, -2 and +3.

    Example 2:
    Input: d = 10
    Output: 4
    Explaination: The steps are +1, +2, +3 and +4.

    T.C : O(log(d))
*/
