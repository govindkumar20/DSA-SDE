class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i=0;i<nums.size();i++) q.push({nums[i],i});
        vector<int> marked(nums.size(),0);
        long long score=0;
        while(!q.empty()){
         int temp=q.top().first;
         int ind=q.top().second;
         q.pop();
         if(!marked[ind]) {
            score+=temp;
         marked[ind]=1;
         if(ind-1>=0 )marked[ind-1]=1;
         if(ind+1<nums.size())marked[ind+1]=1;
         }
        }
        return score;
    }
};