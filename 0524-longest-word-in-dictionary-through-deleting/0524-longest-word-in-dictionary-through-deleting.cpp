class Solution {
public:
bool ispresent(string s1,string s2){ // to check if s1 is present in s2
    int j=0;
    for(int i=0;i<s2.size()&& j<s1.size();i++){
        if(s2[i]==s1[j]) j++;
    }
    return j==s1.size();
}
    string findLongestWord(string s, vector<string>& d) {
        int n=d.size();
        int m=s.size();
        string ans="";
        for(int i=0;i<n;i++)
        {
            string temp=d[i];
            if(ispresent(temp,s)){
              if(ans.size()<temp.size() || (ans.size()==temp.size() && temp<ans)){// to maintain lexicographical order
                ans=temp;
              }
            }
        }
        return ans;
    }
};