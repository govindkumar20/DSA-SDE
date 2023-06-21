class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> mergedintervals;
       if(intervals.size()==0)                //if intervals array is empty
        {
            return mergedintervals;
        }
        sort(intervals.begin(),intervals.end());     //sorting is must
         vector<int> temp=intervals[0];
         for(auto i:intervals)                        //main algo i[0]<=temp[1] for merge
         {
             if(i[0]<=temp[1])
             {
                 temp[1]=max(temp[1],i[1]);
             } else{
                 mergedintervals.push_back(temp);
                 temp=i;
             }
         }
         mergedintervals.push_back(temp);             // pushing remaining temp to ans
         return mergedintervals;
    }
};