class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> permutations;
        sort(nums.begin(),nums.end());
        do{
            permutations.insert(nums);
        } while(next_permutation(nums.begin(),nums.end()));
        vector<vector<int>> v;
        for(auto s:permutations){
            v.push_back(s);
        }
         return v;
    }
};