class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<pair<string,int>> q; // {word,steps}
        q.push({beginWord,1});
        s.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==endWord) return steps;
            for(int i=0;i<word.size();i++){
            char org=word[i];
            for(int ch='a';ch<='z';ch++){
                word[i]=ch;
                if(s.find(word)!=s.end()){
                    s.erase(word);
                    q.push({word,steps+1});
                }
                word[i]=org;

            }
            }
        }
     return 0;
    }
};