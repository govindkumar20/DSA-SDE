class Solution {
public:
    int help(int n,int m, char op){
        if(op=='+') return n+m;
        else if(op=='-') return n-m;
        else if(op=='*') return n*m;
        else if(op=='/') return n/m;
        return 0;
    }
    vector<int> diffWaysToCompute(string exp) {
        int flag=1;
        vector<int> ans;
        for(int i=0;i<exp.size();i++)
        {
            if(!isdigit(exp[i])){   // whenever encounter an operator , divide exp into right left
                                    //use recursion for right left
               flag=0;
               vector<int> left=diffWaysToCompute(exp.substr(0,i));
               vector<int> right=diffWaysToCompute(exp.substr(i+1));
               for(auto p:left){
                for(auto q:right){
                    int res=help(p,q,exp[i]);
                    ans.push_back(res);
                }
               }
            }
        }
        if(flag) ans.push_back(stoi(exp));  // if there is no operator in exp
        return ans;
    }
};