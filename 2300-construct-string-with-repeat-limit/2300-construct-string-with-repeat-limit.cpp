class Solution {
public:
    string repeatLimitedString(string s, int k) {
        int n=s.size();
        map<char,int> m;
        for(auto i:s) m[i]++;
        priority_queue<pair<char,int>> q;
        for(auto i:m) q.push({i.first,i.second});
        string ans="";
        while(!q.empty()){
            int ele=q.top().first;
            int count=q.top().second;
            q.pop();
            int mini=min(k,count);
            int temp=mini;
            while(temp--) ans+=ele;
            count-=mini;
            if(count>0){
                if(q.empty()) break;
                int nextele=q.top().first;
                int nextcount=q.top().second;
                q.pop();
                ans+=nextele;
                nextcount--;
                if(nextcount>0) q.push({nextele,nextcount});
                q.push({ele,count});
            }

        }
        return ans;
    }
};