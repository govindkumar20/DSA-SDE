class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        unordered_map<int,int> m;
        stack<int> st;
        vector<int> ans;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums2[i])
            {
                   st.pop();
            }
            int res=(st.empty())?-1:st.top();
            m.insert({nums2[i],res});
            st.push(nums2[i]);
        }
        for(auto i: nums1)
        {
            ans.push_back(m[i]);
        }
        return ans;
    }
};