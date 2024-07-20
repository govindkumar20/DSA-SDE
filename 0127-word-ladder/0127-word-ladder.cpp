class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;  //{word,steps}
        q.push({beginWord,1});
        s.erase(beginWord);  // in case begin word is also in set
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==endWord) return steps; // if found return steps
            for(int i=0;i<word.size();i++){  // changing each  letter in word
                char original=word[i];
                for(int ch='a';ch<='z';ch++){  // changing prev word into new word by sltering letters
                    word[i]=ch;
                    if(s.find(word)!=s.end()){  // if modified word is present in set that means it is the nearest neighbour
                        s.erase(word); // erase it to avoid same stage in future
                        q.push({word,steps+1});  // modify queue
                    }
                }
                word[i]=original; // changing letters back to original letters begore moving onto the next letters
            }
        }
        return 0;
    }
};