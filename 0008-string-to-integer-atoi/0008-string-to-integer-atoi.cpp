class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        if(n==0) return 0;
        int i=0;
        int ans=0;
        bool isnegative=false;
        //skip blank spaces at start
        while(i<n && s[i]==' ') i++;
        //checking sign
        if(s[i]=='-'){
            isnegative=true;
            i++;
        } else if(s[i]=='+'){
            i++;
        }
        //converting
        while(i<n && '0'<=s[i] && s[i]<='9')
        {
            int digit=s[i]-'0';
            if(ans>(INT_MAX/10) || ans==(INT_MAX/10) && digit>7)
            {
                return isnegative?INT_MIN:INT_MAX;
            }
            ans=(ans*10)+digit;
            i++;
        }
        return isnegative?-ans:ans;

    }
};