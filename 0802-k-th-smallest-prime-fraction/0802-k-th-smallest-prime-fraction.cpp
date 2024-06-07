class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<pair<double,pair<int,int>>> pq;
         for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double fraction = static_cast<double>(arr[i]) / arr[j];
            pq.push({fraction,{arr[i],arr[j]}});
        }
         }
         cout<<pq.top().first<<endl;
        cout<<pq.size()<<endl;
        while(pq.size()!=k)
        {
            pq.pop();
        }
        cout<<pq.size()<<endl;
        vector<int> ans;
        ans.push_back(pq.top().second.first);
        ans.push_back(pq.top().second.second);
        return ans;
    }
};