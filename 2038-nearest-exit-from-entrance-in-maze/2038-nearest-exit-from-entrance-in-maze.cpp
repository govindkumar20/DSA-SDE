class Solution {
public:
    vector<int> xm={-1,0,1,0};
    vector<int> ym={0,1,0,-1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<int,pair<int,int>>> q; // {steps,{i,j}}
        q.push({0,{entrance[0],entrance[1]}});
        maze[entrance[0]][entrance[1]]='+';
        while(!q.empty()){
            int r=q.front().second.first;
            int c=q.front().second.second;
            int steps=q.front().first;
            if((r==0 || r==n-1 || c==0 || c==m-1) && !(r==entrance[0] && c==entrance[1])) return steps;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+xm[i];
                int nc=c+ym[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && maze[nr][nc]=='.'){
                    maze[nr][nc]='+';
                    q.push({steps+1,{nr,nc}});
                }
            }
        }
        return -1; 
    }
};