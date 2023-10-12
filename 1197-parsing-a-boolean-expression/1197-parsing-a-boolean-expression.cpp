class Solution {
public:
    bool parseBoolExpr(string expression) {
        int i=0;
        return solve(expression,i);
    }

    bool solve(string & s,int& i)     // main function
    {
        if(s[i]=='t')
        {
            i++;
            return true;
        }
        else if(s[i]=='f')
        {
            i++;
            return false;
        } else if(s[i]=='!'){
             return func_not(s,i);
        } else if(s[i]=='&') {
            return func_and(s,i);
        } return func_or(s,i);
    }

    bool func_not(string & s,int& i)   // not function
    {
      i+=2;
      auto ret=solve(s,i);
      i++;
      return !ret;
    }

    bool func_and(string& s,int&  i) // and function
    {
        i+=2;
        bool ret=true;
        ret&=solve(s,i);
        while(s[i]!=')')
        {
            i++;
            ret&=solve(s,i);
        }
        i++;
        return ret;
    }

    bool func_or(string & s, int& i)   // or function
    {
        i+=2;
        bool ret=false;
        ret|=solve(s,i);
        while(s[i]!=')')
        {
            i++;
            ret|=solve(s,i);
        }
        i++;
        return ret;
    }
};
