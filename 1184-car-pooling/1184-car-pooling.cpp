class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> v;
        for(int i=0;i<trips.size();i++)
        {
            v.push_back({trips[i][1],trips[i][0]});  // from means bande uthane hai so + hoga
            v.push_back({trips[i][2],-trips[i][0]});   // to  means bande utarne hai  so - hoga

        }
        int count=0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            count+=v[i].second;
            if(count>capacity) return false;
        }
        return true;
    }
};