class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int ans=0;
        int n=apples.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n || pq.size() ;i++)
        {
            if(i<n && apples[i]) pq.push({days[i]+i-1,apples[i]}); //insert apples on ith day
            while(pq.size() && pq.top().first<i) pq.pop(); // remove rotten apples on ith day
            if(pq.size())
            {
                pair<int,int> p=pq.top();  // apples for eating
                pq.pop();
                if(p.second>1) pq.push({p.first,p.second-1});
                ans++;
            }

           
        } return ans;
    }
};