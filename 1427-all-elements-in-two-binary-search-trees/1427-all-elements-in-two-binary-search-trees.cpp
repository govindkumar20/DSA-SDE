
class Solution {
public: 
vector<int> temp;
void dfs(TreeNode* root){
    if(root==NULL) return;
    dfs(root->left);
    temp.push_back(root->val);
    dfs(root->right);
}
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        dfs(root1);
        int n=temp.size();
        dfs(root2);
        int m=temp.size()-n;
        for(auto i:temp) cout<<i<<" ";
        cout<<endl;
        vector<int> ans;
        int i=0; int j=n;
        while(i<n && j<temp.size()){
            if(temp[i]<=temp[j]) {
                ans.push_back(temp[i]);
                i++;
               // ans.push_back(temp[j]);
            } else {
                ans.push_back(temp[j]);
                j++;
                //ans.push_back(temp[i]);
            }
           // i++;j++;
        }
        while(i<n){
            ans.push_back(temp[i]);
            i++;
        }
         while(j<temp.size()){
            ans.push_back(temp[j]);
            j++;
        }
        for(auto i:ans) cout<<i<<" ";
        return ans;

    }
};