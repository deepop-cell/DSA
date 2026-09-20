/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        vector<vector<int>>ans;
        unordered_map<int,int>parent;
        queue<TreeNode*>q;
        q.push(root);
        vector<int>depth(101);
        int d=0;
        depth[root->val]=0;
        while(!q.empty()){
            int sz=q.size();
            vector<int>level;
            for(int i=0;i<sz;i++){
                TreeNode* curr=q.front();
                level.push_back(curr->val);
                depth[curr->val]=d;
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                    parent[curr->left->val]=curr->val;
                }
                if(curr->right){
                    q.push(curr->right);
                    parent[curr->right->val]=curr->val;
                }
            }
            d++;
            ans.push_back(level);
        }
        //now chekc
        if(depth[x]==depth[y] && parent[x]!=parent[y]){
            return true;
        }
        return false;
        
    }
};