class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int leftmin[n];
        int rightmin[n];
            int maxans=0;
            stack<int> st;
            for(int i=0;i<n;i++)
            {
                while(!st.empty() && heights[st.top()]>=heights[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    leftmin[i]=0;
                } else
                {
                      leftmin[i]=st.top()+1;
                }
                st.push(i);
                 }
                 while(!st.empty())
                {
                    st.pop();
                }
                for(int i=n-1;i>=0;i--)
            {
                while(!st.empty() && heights[st.top()]>=heights[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    rightmin[i]=n-1;
                } else
                {
                      rightmin[i]=st.top()-1;
                }
                st.push(i);
                 }
                 for(int i=0;i<n;i++)
                 {
                     maxans=max(maxans,(rightmin[i]-leftmin[i]+1)*heights[i]);
                     
                 }
                 return maxans;
    }
};