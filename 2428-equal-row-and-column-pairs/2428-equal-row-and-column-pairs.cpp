class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> temp=grid;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               swap(grid[i][j],grid[j][i]);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i]==temp[j]) count++;
            }
        }
        return count;
    }
};