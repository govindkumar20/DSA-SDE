class Solution {
public:
    string originalDigits(string s) {
         vector<int> v(26, 0);
        for (char c : s) v[c - 'a']++;

       

        string ans = "";
        vector<int> result(10, 0);  // To store count of each digit found

        // Check for unique characters in specific order
        result[0] = v['z' - 'a'];
        result[2] = v['w' - 'a'];
        result[4] = v['u' - 'a'];
        result[6] = v['x' - 'a'];
        result[8] = v['g' - 'a'];

        result[1] = v['o' - 'a'] - result[0] - result[2] - result[4];
        result[3] = v['h' - 'a'] - result[8];
        result[5] = v['f' - 'a'] - result[4];
        result[7] = v['s' - 'a'] - result[6];
        result[9] = v['i' - 'a'] - result[5] - result[6] - result[8];

        // Construct the result string
        for (int i = 0; i <= 9; i++) {
            ans += string(result[i], '0' + i);
        }

        return ans;
    }
};