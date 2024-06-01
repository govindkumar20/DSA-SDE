class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // int n=board.size();
        // int m=board[0].size();
        set<string> s;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    string temp="("+string(1,board[i][j])+")";
                    if(!s.insert(temp+to_string(i)).second ||
                    !s.insert(to_string(j)+temp).second ||
                    !s.insert(to_string(i/3) + temp + to_string(j/3)).second ){
                        return false;
                    }
                    
                }
            }
        }
        return true;
    }
};