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
    void generate(TreeNode* root,vector<string>&res,string & curr){
        if(!root->left && !root->right){
            res.push_back(curr);
            return;
        }
        //now we have two options to go.
        //left jau to . 
        if(root->left){
           curr.push_back(root->left->val+'0');
         generate(root->left ,res, curr);
         curr.pop_back();
        }
        if(root->right){
            curr.push_back(root->right->val+'0');
            generate(root->right,res,curr);
            curr.pop_back();
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        int num=root->val;
        string curr="";
        curr.push_back(root->val +'0');
        vector<string>res;
        generate(root,res,curr);
        int ans=0;
        for(auto &x:res){
            ans+=stoi(x,nullptr,2);
        }
        return ans;
    }
};