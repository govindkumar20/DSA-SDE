class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> ps(n);  
        vector<int> ns(n);  
        stack<int> st;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            ps[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            ns[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            ans = max(ans, (ns[i] - ps[i] - 1) * heights[i]);
        }

        return ans;
    }
};
