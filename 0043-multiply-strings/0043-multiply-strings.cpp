class Solution {
public:
    string multiply(string num1, string num2) {
      int n1=num1.size();
      int n2=num2.size();
      if(num1=="0" || num2=="0") return "0";
      vector<int> v(n1+n2,0);
      for(int i=n1-1;i>=0;i--){
        for(int j=n2-1;j>=0;j--){
          v[i+j+1]+=(num1[i]-'0')*(num2[j]-'0'); // add to least significast position
          v[i+j]+=v[i+j+1]/10; //carry to be added one pos before
          v[i+j+1]%=10;   // actual val to be added
        }
      }
      int i=0;
      string ans="";
      while( v[i]==0) i++;  // bcz of leading 0s
      while(i<v.size()) ans+=to_string(v[i++]);
      return ans;
    }
};