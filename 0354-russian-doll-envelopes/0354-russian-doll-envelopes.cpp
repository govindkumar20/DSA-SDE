class Solution {
     static bool cmp(vector<int>& a, vector<int>& b){  // if heights are same , sort widths in dec order to avoid duplicacy
    if(a[0]==b[0]) return a[1]>b[1];   
    return a[0]<b[0];
   }
public:
   
   
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> lis;
        for(int i=0;i<n;i++){
            int temp=envelopes[i][1];
            int ind=lower_bound(lis.begin(),lis.end(),temp)-lis.begin();
            if(ind>=lis.size()) lis.push_back(temp); //agr lis me koi bhi isss se bada present nhi hai to isko last me push back kr do
            else lis[ind]=temp;  // agr hai to isko uss se replace kr do
            
        }
         return lis.size();
      
    }
};