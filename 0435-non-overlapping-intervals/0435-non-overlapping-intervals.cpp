class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> prev = intervals[0];
        int count = -1;
        for (auto i : intervals) {
            if (i[0] < prev[1]) {
                count++;
            } else {
                prev = i;
            }
        }
        return count;
    }
};
