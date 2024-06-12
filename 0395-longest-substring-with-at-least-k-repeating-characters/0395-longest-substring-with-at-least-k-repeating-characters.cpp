class Solution {
public:
    int longestSubstring(string s, int k) {
        map<char,int> m;
        for(auto i:s) m[i]++;
        int ind=0;
        
        while(ind<s.size() && m[s[ind]]>=k){  //first element whose occurence is less than k 
            ind++;                              // if found divide string into left and right and use recursion
                                              // else return size()
        }
            if(ind==s.size()) return s.size();
        
               int left=longestSubstring(s.substr(0,ind),k);
                 int right=longestSubstring(s.substr(ind+1),k);
            
        
        return max(left,right);
    }
};