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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;//node,maxval till now
        q.push({root,root->val});
        int cnt=0;
        while(!q.empty()){
        auto it=q.front();
        q.pop();
        TreeNode* curr=it.first;
        int max_tillnow=it.second;
        if(curr->val>=max_tillnow){
            cnt++;
        }
        if(curr->left){
            int m=max(max_tillnow,curr->left->val);
            q.push({curr->left,m});
        }
        if(curr->right){
            int m=max(max_tillnow,curr->right->val);
            q.push({curr->right,m});
        }
        }
        return cnt;
    }
};