class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>> ans;
        for(int i=0;i<searchWord.size();i++)
        {
            auto s=lower_bound(products.begin(),products.end(),searchWord.substr(0,i+1));
            auto e=lower_bound(s,min(s+3,products.end()),searchWord.substr(0,i)+(char)(searchWord[i]+1));
            ans.push_back(vector<string>(s,e));
        }
        return ans;
    }
};