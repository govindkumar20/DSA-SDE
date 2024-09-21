class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int> lastIdx(26,-1);
        for(int i=0;i<n;i++){
            lastIdx[s[i]-'a']=i;
        }
        vector<int> ans;
        int start=0;
        int end=0;
        for(int i=0;i<n;i++){
           end=max(end,lastIdx[s[i]-'a']);
           if(i==end) {
            ans.push_back(end-start+1);
            start=i+1;
           }
        }
        return ans;
    }
};