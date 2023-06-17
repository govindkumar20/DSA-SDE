class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m{{'I',1}
                                ,{'V',5},
                                {'X',10},
                                {'L',50},
                                {'C',100},
                                {'D',500},
                                {'M',1000}};
        int prev=0;
        int result=0;
        for(int i=s.size();i>=0;i--)
        {
              if(m[s[i]]>=prev)
              {
                  result+=m[s[i]];
              } else
              {
                  result-=m[s[i]];
              }
              prev=m[s[i]];
        }
        return result;
    }
};