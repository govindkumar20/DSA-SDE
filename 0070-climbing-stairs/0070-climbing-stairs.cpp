class Solution {
public:
    int climbStairs(int n) {
        int prev=1;
        int prev2=0;
        for(int i=0;i<n;i++)
        {
           int curri=prev+prev2;
            prev2=prev;
        prev=curri;

        }
        return prev;
    }
};