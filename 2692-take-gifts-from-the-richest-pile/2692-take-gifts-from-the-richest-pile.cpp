
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> q(gifts.begin(),gifts.end());
        while(k--){
            long long temp=q.top();
            q.pop();
            q.push(sqrt(temp));
        }
        long long sum=0;
        while(!q.empty()){
            sum+=q.top();
            q.pop();
        }
        return sum;
    }
};