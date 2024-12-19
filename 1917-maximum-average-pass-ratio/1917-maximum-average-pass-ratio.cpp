struct cmp{
bool operator()(pair<int,int> a, pair<int,int> b){
    double one=(a.first+1)/(double)(a.second+1)-(a.first)/(double)(a.second);
    double two=(b.first+1)/(double)(b.second+1)-(b.first)/(double)(b.second);
    return one<two;
}
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;
        for(auto i:classes){
            q.push({i[0],i[1]});
        }
        while(extraStudents--){
            int temp1=q.top().first;
            int temp2=q.top().second;
            q.pop();
            q.push({temp1+1,temp2+1});
        }
        double ans=0;
        while(!q.empty()){
           ans+=double(q.top().first)/q.top().second;
           q.pop();
        }
        return ans/(double)classes.size();
    }
};