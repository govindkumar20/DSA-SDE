class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        int temp=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=i;
            temp+=arr[i];
            if(sum==temp) ans++;
        }
        return ans;
    }
};