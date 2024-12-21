class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>> q(arr.begin(),arr.end());
        int rank=1;
        map<int,int> m;
        int prev;
        while(!q.empty()){
           if(m.find(q.top())==m.end()){
            m[q.top()]=rank;
            rank++;
           }
              q.pop();
        }
        for(int i=0;i<n;i++){
            arr[i]=m[arr[i]];
        }
        return arr;
    }
};