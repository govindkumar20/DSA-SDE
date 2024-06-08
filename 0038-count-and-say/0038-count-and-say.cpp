class Solution {
public:
    string countAndSay(int n,string s="1") {
      if(n==1) return s;
      int i=0;
      int j;
      int length=s.size();
      string res="";
      while(i<length){
        j=i;
        while(i<length && s[i]==s[j]) i++;
        res+=to_string(i-j)+s[j];
      }
      return countAndSay(n-1,res);

    }
};