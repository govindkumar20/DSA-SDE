class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>> s;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int k=j+1;
                int e=n-1;
                while(k<e)
                {
                    long long sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[k]+(long long)nums[e];
                    if(sum==target)
                    {
                        s.insert({nums[i],nums[j],nums[k],nums[e]});
                        k++;
                        e--;
                    }
                    else if(sum<target)
                    {
                        k++;
                    } else{
                        e--;
                    }
                }
            }
        }
        for(auto i: s)
        {
        ans.push_back(i);
        }
        return ans;
    }
};