
 bool compare(string a,string b)
     {
        return a+b>b+a;
     }

class Solution {
public:
    

    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto i:nums)
        {
            v.push_back(to_string(i));
        }
        sort(v.begin(),v.end(),compare);
        string ans;
        for(auto i:v)
        {
            ans+=i;
        }
         return (ans[0]=='0'?"0":ans);

    }
};