class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a) pq.push({a,'a'});
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});
        string s="";
        while(pq.size()>1){
            pair<int,char> p1=pq.top();
            pq.pop();
            pair<int,char> p2=pq.top();
            pq.pop();
            if(p1.first>=2)
            {
              s+=p1.second;
              s+=p1.second;
              p1.first-=2;
            } else{
              s+=p1.second;
              p1.first-=1;
            }
            if(p2.first>=2 && p2.first>=p1.first){
              s+=p2.second;
              s+=p2.second;
              p2.first-=2; 
            } else{
                 s+=p2.second;
              p2.first-=1;
            }
            if(p1.first>0) pq.push(p1);
            if(p2.first>0) pq.push(p2);
        }
            if(pq.empty()) return s;
            if(pq.top().first>=2)
            {
                s+=pq.top().second;
                s+=pq.top().second;
            } else{
                s+=pq.top().second;
            }
        return s;
    }
};