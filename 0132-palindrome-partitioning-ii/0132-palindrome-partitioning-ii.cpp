class Solution {
public:  
    int t[2001][2001];
    bool isPalindrome(string &s, int i, int j){
        while (i < j){
            if (s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    int solve(string &s, int i, int j){
        if (i >= j){
            return 0;
        }

        if (t[i][j] != -1){
            return t[i][j];
        }

        if (isPalindrome(s, i, j) == true){
            return 0;
        }

        int ans = INT_MAX;
        for (int k = i; k < j; k++){
            if (isPalindrome(s, i, k)){
                ans = min(ans, 1 + solve(s, k + 1, j));
            }
        }

        return t[i][j] = ans;
    }

    int minCut(string s){
        int i = 0;
        int j = s.length() - 1;
        memset(t, -1, sizeof(t));
        return solve(s, i, j);
    }
};