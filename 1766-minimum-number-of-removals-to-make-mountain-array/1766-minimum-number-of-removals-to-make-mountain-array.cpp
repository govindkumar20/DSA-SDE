class Solution {
public:
    int length_lis(vector<int>& nums1) {
        vector<int> lis;
        
        for (int x : nums1) {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            if (it == lis.end()) 
                lis.push_back(x);
            else 
                *it = x;
        }
        
        return lis.size();
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        int ans=n;
        for(int i=1;i<n-1;i++){
            vector<int> v1(nums.begin(),nums.begin()+i+1);
           int n1=length_lis(v1);
           vector<int> v2(nums.begin()+i,nums.end());
           reverse(v2.begin(),v2.end());
           int n2=length_lis(v2);
             if (n1 > 1 && n2 > 1) {
                ans = min(ans, n - (n1 + n2 - 1));
            }
        }
        return ans;
    }
};

/*
2,1,1,5,6,2,3,1
0,1,2,3,4,5,6,7
*/