class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        map<char,int> m;
        string temp1="qwertyuiopQWERTYUIOP";
        for(auto i:temp1) m[i]=1;
        string temp2="ASDFGHJKLasdfghjkl";
        for(auto i:temp2) m[i]=2;
        string temp3="ZXCVBNMzxcvbnm";
        for(auto i:temp3) m[i]=3;

        for(int i=0;i<words.size();i++){
          int flag=-1;
          bool var=true;
            for(auto j:words[i]){
             if(flag==-1) flag=m[j];
             else if(flag!=m[j]) var=false;
            }
           if(var) ans.push_back(words[i]);
        }
        return ans;
    }
};