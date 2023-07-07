class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int start=0;
        int end=n-1;
        int ans=0;
        while(start<end)
        {
            ans=max(ans,(end-start)*min(height[start],height[end]));
            height[start]<height[end] ? start++ : end--;
        }
          return ans;
    }
};