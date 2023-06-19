class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1,1);
        long c=1;
        for(int j=1;j<rowIndex;j++)
        {
            c=c*(rowIndex-j+1)/j;
            row[j]=c;
        }
        return row;
    }
};