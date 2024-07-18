class Solution {
public:
    vector<int> xm={-1,0,1,0};
    vector<int> ym={0,1,0,-1};
    int dfs(vector<vector<int>>& grid,int i,int j,int index){  //basic dfs
        int n=grid.size();
        if(i<0 || j<0 || i>n-1 || j>n-1 || grid[i][j]!=1) return 0;
        grid[i][j]=index;   // marking cells with index
        int ar=0;
        for(int p=0;p<4;p++){
          ar+=dfs(grid,i+xm[p],j+ym[p],index);
        }
        return ar+1;  //returning area of island
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1) return 1;
        int index=2; // 2 bcz 0,1 already used by binard matrix grid
        int res=0;
        unordered_map<int,int> area; // index,area of island
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    area[index]=dfs(grid,i,j,index);
                    res=max(res,area[index]);
                    index++;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int> s;  // insert neighbours in set
                    int c=1;
                    // for(int p=0;p<4;p++){
                    //     if(i>0 && j>0 && i<n-1 && j<n-1){
                    //         s.insert(grid[i+xm[p]][j+ym[p]]);
                    //     }
                    // }
                    if(i>0) s.insert(grid[i-1][j]);
                    if(j>0) s.insert(grid[i][j-1]);
                    if(i<n-1) s.insert(grid[i+1][j]);
                    if(j<n-1) s.insert(grid[i][j+1]);
                    for(int q:s){
                        c+=area[q];  // changing each 0 to get max area
                        res=max(res,c);  // storing the max area
                    }
                }
            }
        }

     return res;
    }
};