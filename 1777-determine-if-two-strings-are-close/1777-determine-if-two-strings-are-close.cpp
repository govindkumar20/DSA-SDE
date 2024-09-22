class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        if(n!=m) return false;
        vector<int> count1(26,0);
        vector<int> count2(26,0);
        for(int i=0;i<n;i++) count1[word1[i]-'a']++;
        for(int i=0;i<n;i++) count2[word2[i]-'a']++;
        sort(count1.begin(),count1.end());
        sort(count2.begin(),count2.end());
        unordered_set<char> s;
        for(auto i:word2) s.insert(i);
        for(int i=0;i<n;i++){
            if(s.find(word1[i])==s.end()) return false;
        }
        for(int i=0;i<26;i++){
            if(count1[i]!=count2[i]) return false;
        }
        return true;
    }
};