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
    void solve(TreeNode* curr,string & temp,vector<string>&res){
        if(!curr->left && !curr->right){
            res.push_back(temp);
            return ;
        }
        //now we have two options 
        //go left
        temp+="->";
        if(curr->left){
        int oldSize=temp.size();
        temp+=to_string(curr->left->val);
        solve(curr->left,temp,res);
        temp.resize(oldSize);
        }
        //GO RIGHT......
        if(curr->right){
        int oldSize=temp.size();
        temp+=to_string(curr->right->val);
        solve(curr->right,temp,res);
        temp.resize(oldSize);
        }

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string temp;
        temp+=to_string(root->val);
        solve(root,temp,ans);
        return ans;
    }
};