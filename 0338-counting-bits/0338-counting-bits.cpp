class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++)
        {
            ans[i]=countSetBits(i);
        }
        return ans;

    }

    int countSetBits(int n)
    {
        int count=0;
        while(n)
        {
            count+=n&1;
            n>>=1;
        }
        return count;
    }
};