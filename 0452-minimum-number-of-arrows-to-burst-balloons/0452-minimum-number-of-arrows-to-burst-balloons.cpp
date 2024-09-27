class Solution {
public:
   static bool cmp(vector<int>& a1, vector<int>& a2){
        if(a1[1]!=a2[1]) return a1[1]<a2[1];
        return a1[0]<a2[0];
    }
// [1,6],[2,8],[7,12],[10,16]
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());
        vector<int> temp=points[0];
        vector<vector<int>> ans;
        for(auto i:points){
            if(i[0]<=temp[1]){
                temp[1]=min(temp[1],i[1]);
            } else{
                ans.push_back(temp);
                temp=i;
                
            }
        }
        ans.push_back(temp);
        return ans.size();
    }};