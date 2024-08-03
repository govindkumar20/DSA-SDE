class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parents(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (parents[leftChild[i]] == -1) {
                    parents[leftChild[i]] = i;
                } else {
                    return false;
                }
            }

            if (rightChild[i] != -1) {
                if (parents[rightChild[i]] == -1) {
                    parents[rightChild[i]] = i;
                } else {
                    return false;
                }
            }
        }

        int root = -1;
        for (int i = 0; i < n; i++) {
            if (parents[i] == -1) {
                if (root == -1) {
                    root = i;
                } else {
                    return false;
                }
            }
        }

        if (root == -1) return false;

        unordered_set<int> s;
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (s.find(node) != s.end()) return false;
            s.insert(node);
            if (leftChild[node] != -1) q.push(leftChild[node]);
            if (rightChild[node] != -1) q.push(rightChild[node]);
        }

        return s.size() == n;
    }
};
