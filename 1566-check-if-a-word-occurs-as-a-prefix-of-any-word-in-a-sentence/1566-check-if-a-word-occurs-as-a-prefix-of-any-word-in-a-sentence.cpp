class Solution {
public:
    bool check(string& s, string& target) {
        if (s.size() < target.size()) return false;
        for (int i = 0; i < target.size(); i++) {
            if (s[i] != target[i]) return false;
        }
        return true;
    }

    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size();
        vector<string> v;
        int i = 0, j = 0;

        while (j < n) {
            if (sentence[j] == ' ') {
                v.push_back(sentence.substr(i, j - i));
                i = j + 1;
            }
            j++;
        }

        if (i < n) {
            v.push_back(sentence.substr(i, j - i));
        }

        for (int k = 0; k < v.size(); k++) {
            if (check(v[k], searchWord)) {
                return k + 1;
            }
        }

        return -1;
    }
};
