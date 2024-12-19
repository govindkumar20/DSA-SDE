class Solution {
public: 
    bool isSame(string s){
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[0]) return false;
        }
        return true;
    }

    int maximumLength(string s) {
        int n=s.size();
        int ans=-1;
        map<string,int> m;
        for(int i=0;i<n;i++){
            string temp="";
           // temp+=s[i];
           // m[temp]++;
            for(int j=i;j<n;j++){
                if(s[j]==s[i]){
                     temp+=s[j];
             m[temp]++;
                } else break;
             
            }
            if(m[temp]>=3) ans=max(ans,static_cast<int>(temp.size()));
        }
      
        return ans;
    }
};