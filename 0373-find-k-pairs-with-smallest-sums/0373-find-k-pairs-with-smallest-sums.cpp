#include <vector>
#include <map>
#include <utility>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        priority_queue<pair<int, pair<int, int>>> m;
        
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                int sum = nums1[i] + nums2[j];
                if(m.size()<k)m.push({sum, {nums1[i], nums2[j]}});
                else if(sum<m.top().first)
                {
                    m.pop();
                    m.push({sum, {nums1[i], nums2[j]}});
                } else {
                    break;
                }
            }
        }
        
        vector<vector<int>> result;
      
        while(!m.empty())
        {
            result.push_back({m.top().second.first,m.top().second.second});
            m.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
