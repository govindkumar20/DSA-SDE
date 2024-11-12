
class Solution {
public:
vector<int> ans;
    //making graph
    void makeGraph(TreeNode* root,vector<vector<int>>& graph){
        if(root->left){
            
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            makeGraph(root->left,graph);
        }
        if(root->right){
           
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val); 
            makeGraph(root->right,graph);
        }
    }

    void findNodes(vector<vector<int>>& graph,int node,int k, int distance,int parent){
        if(distance==k){
            ans.push_back(node);
        }
        for(auto i:graph[node]){
            if(i!=parent){
            findNodes(graph,i,k,distance+1,node);
            }
        }
    }
    

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<vector<int>> graph(501);
        makeGraph(root,graph);
        findNodes(graph,target->val,k,0,-1);
        return ans;
    }
};