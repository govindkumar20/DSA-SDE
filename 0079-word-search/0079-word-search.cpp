class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(adjacentsearch(0,board,word,i,j)) return true;
            }
        }
        return false;
    }

    bool adjacentsearch(int index, vector<vector<char>>& board,string& word,int i, int j)
    {
        if(index==word.length()) return true;
        if(i<0||i>board.size()-1||j<0||j>board[0].size()-1||board[i][j]!=word[index]) return false;
        board[i][j]='.';
        bool next=adjacentsearch(index+1,board,word,i+1,j)||
        adjacentsearch(index+1,board,word,i-1,j)||
        adjacentsearch(index+1,board,word,i,j+1)||
        adjacentsearch(index+1,board,word,i,j-1);
        board[i][j]=word[index];
        return next;

    }
};