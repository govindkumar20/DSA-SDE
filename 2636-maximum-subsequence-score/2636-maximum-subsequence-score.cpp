class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        priority_queue<int,vector<int>,greater<int>> q;
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++) temp.push_back({nums2[i],nums1[i]});
        sort(temp.begin(),temp.end());
        long long sum=0;
        long long score=0;
        for(int i=n-1;i>=0;i--){
            q.push(temp[i].second);
            sum+=temp[i].second;
            if(q.size()>k){
                sum-=q.top();
                q.pop();
            }
            if(q.size()==k) score=max(score,temp[i].first*sum);
        }
         return score;
    }
};