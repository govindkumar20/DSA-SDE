class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        map<string,int> m;
        for(int i=0;i+9<n;i++)
        {
           m[s.substr(i,10)]++;
        }
        vector<string> v;
        for(auto i:m){
            if(i.second>1) v.push_back(i.first);
        }
        return v;
    }
};