class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int> ans;
        int count=0;
        int total=row*col;
        int startingrow=0;
        int endingrow=row-1;
        int startingcolumn=0;
        int endingcolumn=col-1;
        while(count<total)
        {
            for(int i=startingcolumn;i<=endingcolumn && count<total;i++)
            {
                ans.push_back(matrix[startingrow][i]);
                count++;
            }
            startingrow++;
            for(int i=startingrow;i<=endingrow && count<total;i++)
            {
                ans.push_back(matrix[i][endingcolumn]);
                count++;
            }
            endingcolumn--;
            for(int i=endingcolumn;i>=startingcolumn && count<total;i--)
            {
                ans.push_back(matrix[endingrow][i]);
                count++;
            }
            endingrow--;
            for(int i=endingrow;i>=startingrow && count<total;i--)
            {
                ans.push_back(matrix[i][startingcolumn]);
                count++;
            }
            startingcolumn++;;
        }
        return ans;
    }
};