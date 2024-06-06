#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freqMap;
        for (const auto& word : words) {
            freqMap[word]++;
        }

        auto comp = [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second > b.second;  // Lexicographical order for ties
            }
            return a.first < b.first;  // Frequency order
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);

        for (const auto& entry : freqMap) {
            pq.emplace(entry.second, entry.first);
        }

        vector<string> ans;
        while (k-- && !pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
