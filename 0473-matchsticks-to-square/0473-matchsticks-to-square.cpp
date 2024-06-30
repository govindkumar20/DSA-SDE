class Solution {
public:
    
    bool DFS(vector<int>& m,vector<int>& v, int i){
        if(i==-1){
        if(v[0]==0 and v[1]==0 and v[2]==0 and v[3]==0){
                return true;    
        } else {
            return false;
        }
        }
        for(int j=0;j<4;j++){
            if(m[i]>v[j]) continue;
            v[j]-=m[i];
            if(DFS(m,v,i-1)) return true;
            v[j]+=m[i];
        }
        return false;
       
        
    }
    bool makesquare(vector<int>& m) {
        int sum=0;
        for(int i=0;i<m.size();i++){
            sum+=m[i]; 
        }
        if(sum%4!=0){
            return false;
        }
        sort(m.begin(),m.end());
        vector<int> v(4,sum/4);
        int n=m.size();
        return DFS(m,v,n-1);
    }
};