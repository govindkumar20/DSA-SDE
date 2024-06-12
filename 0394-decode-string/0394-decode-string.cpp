class Solution {
public:
    string decodeString(string s) {
        int currnum=0;string currstr="";
        stack<string> s1;
        stack<int> s2;
        for(auto i:s){
            if(isdigit(i)) currnum = currnum * 10 + (i - '0');  //to handle multi digit numbers
            else if(i=='['){ // push curnum and currstring to stacks and initialize to empty
                s1.push(currstr);
                s2.push(currnum);
                currstr="";
                currnum=0;
            } else if(i==']'){ // update currstr  acc to rule
                int prev=s2.top();
                s2.pop();
                string prevstring=s1.top();
                s1.pop();
                  string temp="";
                  while(prev--){
                    temp+=currstr;
                  }
                currstr=prevstring+temp;
            } else{ // update currstr
                currstr+=i;
            }
        }
        return currstr;
    }
};