class Solution {
public:
    int characterReplacement(string s, int k) {
        //will use sliding window
        map<char,int> m;
        int l=0;
        int ans=0;
        int max_occur=0;
        for(int r=0;r<s.size();r++){
            m[s[r]]++;
            max_occur=max(max_occur,m[s[r]]);
            while((r-l+1)-max_occur>k){
                m[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }

};