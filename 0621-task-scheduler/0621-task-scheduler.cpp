class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26);
        int maxi=0;
        int e=0;
        for(auto i:tasks) v[i-'A']++;
        for(auto i:v) maxi=max(maxi,i);
        for(auto i:v) {
            if(i==maxi) e++;
        }
        return max(int(tasks.size()),(maxi-1)*(n+1)+e);

    }
};