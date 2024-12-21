class Solution {
public:
    bool isPermutation(string s1, string s2){
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]) return false;
        }
        return true;
 
    }

    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        for(int i=0;i<=m-n;i++){
          if(isPermutation(s1,s2.substr(i,s1.size()))) return true; 
        }
        return false;
    }
};