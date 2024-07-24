class Solution {
public:
    int lcs(string a,string b){  // lcs
        int n=a.length();
        int m=b.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }

    static bool cmp( string& a,  string & b){   // sorting on the basis of length
        return a.length()<b.length();
    }

    int longestStrChain(vector<string>& words) {
        //process : sorting->lis->lcs
        int n=words.size();
        sort(words.begin(),words.end(),cmp);
        vector<int> len(n,1);
        for(int i=0;i<n;i++){            //lis
          for(int j=0;j<i;j++){
            if(words[i].length()==words[j].length()+1 &&  // difference of lengths must be 1
               lcs(words[i],words[j])==words[j].length() &&   // lcs must be equal to prev word
               len[i]<len[j]+1){   // if its a same sequence
                len[i]=len[j]+1;
               }
          }

        }
        return *max_element(len.begin(),len.end());  // return the max length
    }
};