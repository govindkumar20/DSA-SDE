class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_set<char> setChar;
        int start=0;
        int end=0;
        int ans=0;
       while(start<n && end<n)
       {
           if(setChar.find(s[start])==setChar.end())
           {
               setChar.insert(s[start]);
               start++;
               ans=max(ans,start-end);
           } else{
               setChar.erase(s[end]);
               end++;
           }
       }
       return ans;
    }
};