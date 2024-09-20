class Solution {
public:
    bool isSame(vector<char>& temp1, vector<char>& temp2, int n){
        for(int i=0; i<n; i++){
            if(temp1[i] != temp2[i]) 
                return false;
        }
        return true;
    }

    bool backspaceCompare(string s, string t) {
        vector<char> temp1, temp2;
        
        // Process first string
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '#') 
                temp1.push_back(s[i]);
            else if(!temp1.empty())  // Check before popping
                temp1.pop_back();
        }

        // Process second string
        for(int i = 0; i < t.size(); i++){
            if(t[i] != '#') 
                temp2.push_back(t[i]);
            else if(!temp2.empty())  // Check before popping
                temp2.pop_back();
        }

        // Check size and contents
        if(temp1.size() != temp2.size()) 
            return false;

        return isSame(temp1, temp2, temp1.size());
    }
};
