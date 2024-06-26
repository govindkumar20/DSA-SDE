class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++)
        {
            pq.push({abs(x-arr[i]),arr[i]});
        }
        while(pq.size()!=k)
        {
            pq.pop();
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};