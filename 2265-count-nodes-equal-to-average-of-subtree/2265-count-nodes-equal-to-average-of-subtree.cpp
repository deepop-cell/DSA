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
    pair<int,int> dfs(TreeNode* root,int &ans){
        if(!root){
            return {0,0};
        }
        auto left=dfs(root->left,ans);
        auto right=dfs(root->right,ans);
        int leftsum=left.first;
        int leftcount=left.second;
        int rightsum=right.first;
        int rightcount=right.second;
        int sum=root->val+rightsum+leftsum;
        int total=leftcount+rightcount+1;
        if(sum/total==root->val){
            ans++;
        }
        return {sum,total};
    }
    int averageOfSubtree(TreeNode* root) {
       int ans=0;
       dfs(root,ans);
       return ans;
    }
};