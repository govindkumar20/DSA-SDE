class Solution {
public:
    int compress(vector<char>& chars) {
       int n=chars.size();
       int count=1;
       string ans="";
       for(int i=0;i<n;i++)
       {
        while(i<n-1 && chars[i+1]==chars[i])
        {
            count++;
            i++;
        }
        ans+=chars[i];
        if(count==1) continue;
        ans+=to_string(count);
        count=1;
       }
       //return ans.length();
       chars.clear();
       for(auto i:ans)
       {
        chars.push_back(i);
       }
       return chars.size();
    }
};