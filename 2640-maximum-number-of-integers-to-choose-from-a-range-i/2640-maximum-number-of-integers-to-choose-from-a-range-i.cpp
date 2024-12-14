class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> s(banned.begin(),banned.end());
        int sum=0;
        int count=0;
        for(int i=1;i<=n;i++){
            if(s.find(i)==s.end()){
             if(sum+i<=maxSum){
                sum+=i;
                count++;
             }
            }
        }
        return count;
    }
};