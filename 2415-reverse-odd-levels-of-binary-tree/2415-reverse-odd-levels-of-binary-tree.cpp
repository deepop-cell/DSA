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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int dist=0;
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty()){
            int sz=q.size();
            vector<int>level;
            for(int i=0;i<sz;i++){
                auto it=q.front();
                q.pop();
                level.push_back(it->val);
                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }
            }
            ans.push_back(level);
        }
        queue<TreeNode*>q2;
        q2.push(root);
        int level=0;
        while(!q2.empty()){
            int sz=q2.size();
            for(int i=0;i<sz;i++){
                auto it=q2.front();
                q2.pop();
            if(level%2!=0){
                it->val=ans[level][sz-i-1];
            }
            if(it->left){
                q2.push(it->left);
            }
            if(it->right){
                q2.push(it->right);
            }
            }
            level++;
        }
        return root;
    }
};