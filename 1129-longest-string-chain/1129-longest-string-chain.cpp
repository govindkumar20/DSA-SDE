class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),sortByLength);
        unordered_map<string,int> dp;
        int ans=0;
        for(string word:words)
        {
            for(int i=0;i<word.size();i++)
            {
                string predecessor=word.substr(0,i)+word.substr(i+1);
                dp[word]=max(dp[word],dp[predecessor]+1);
            }
            ans=max(ans,dp[word]);
        }
        return ans;
    }

    static bool sortByLength(string&s1 , string& s2)
    {
        return s1.length()<s2.length();
    }
};