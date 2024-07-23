class Solution {
 
public:
    int findLongestChain(vector<vector<int>>& pairs) {
       
        sort(pairs.begin(),pairs.end()); // now left is not aur problem as it gets sorted
        vector<int> lis;  // basic lis with slight modificationsf
        for(int i=0;i<pairs.size();i++){
            int ele=pairs[i][0];
            auto ind=lower_bound(lis.begin(),lis.end(),ele);
            if(ind==lis.end()) lis.push_back(pairs[i][1]);  // if theres no one greater than pair[0] insert pair[1] at last
            else *ind=min(*ind,pairs[i][1]);  // if there is someone greater find the smallest one
        }
        return lis.size();
    }
};