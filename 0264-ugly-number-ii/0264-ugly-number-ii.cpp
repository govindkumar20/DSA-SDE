class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long,vector<long long>, greater<long>> pq;
        map<long long,int> m;
        pq.push(1);
        long popped,count=0;
        
        while(count<n)
        {
            popped=pq.top();
            pq.pop();
            if(m[popped]==0)
            {
                pq.push(popped*2);
                pq.push(popped*3);

                pq.push(popped*5);
                count++;
                m[popped]=1;
            }
            
           
        }
        return int(popped);
        
    }
};