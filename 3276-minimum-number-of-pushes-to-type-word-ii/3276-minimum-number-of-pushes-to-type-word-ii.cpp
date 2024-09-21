class Solution {
public:
    int minimumPushes(string word) {
        vector<int> count(26,0);
        for(int i=0;i<word.size();i++) count[word[i]-'a']++;
        sort(count.rbegin(),count.rend());
        int push=1;
        int ans=0;
        for(int i=0;i<26;i++){
            if(i>=8 && i%8==0) push++;
            ans+=push*count[i];
        }
        return ans;
    }
};