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
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        int l=height(root->left);
        int r=height(root->right);
        return 1 + max(l,r);
    }
    int p(int a, int b){
        //find power using binary exponentiation
        if(b==0){
            return 1;
        }
        int half=pow(a,b/2);
        if(b%2==0){
            return half*half;
        }
        else{
            return half* half * a;
        }
        return 1;
    }
    void dfs(TreeNode* root,vector<vector<string>>&ans,int r, int c,int h){
        if(!root){
            return;
        }
        ans[r][c]=to_string(root->val);
            dfs(root->left,ans,r+1,c-p(2,h-r-1),h);
            dfs(root->right,ans,r+1,c+p(2,h-r-1),h);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h=height(root)-1;
        int rows=h+1;
        int cols=p(2,h+1)-1;
        vector<vector<string>>ans(rows,vector<string>(cols,""));
        dfs(root,ans,0,(cols-1)/2,h);
        return ans;

    }
};