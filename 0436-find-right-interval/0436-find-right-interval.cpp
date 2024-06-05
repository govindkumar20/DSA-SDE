class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
       
        if(intervals[0][0]==intervals[0][1] && intervals.size()==1) return {0};
         if(intervals.size()<=1) {
            
             return {-1};
        }
        int n=intervals.size();
        map<int,int> m;
        vector<int> v(n,-1);
        for(int i=0;i<n;i++) m[intervals[i][0]]=i;
        for(int i=0;i<n;i++)
        {
          auto it=m.lower_bound(intervals[i][1]);
          if(it!=m.end())
          {
            v[i]=it->second;
          }
        }
        return v;
    }
};