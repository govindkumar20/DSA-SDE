class Solution {
public:
    void rev(string& s) {
        reverse(s.begin(), s.end());
    }
    void inv(string& s) {
        int size = s.size();
        for (int i = 0; i < size; i++) {
            s[i] = s[i] == '0' ? '1' : '0';
        }
    }
    char findKthBit(int n, int k) {
        map<int, string> m;
        m[1] = "0"; 
        for (int i = 2; i <= n; i++) {
            string temp = m[i-1];
            inv(temp);        
            rev(temp);      
            m[i] = m[i-1] + "1" + temp;
        }
        return m[n][k-1];
    }
};
