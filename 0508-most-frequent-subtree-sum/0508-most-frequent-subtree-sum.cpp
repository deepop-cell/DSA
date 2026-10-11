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
    int dfs(TreeNode* root,unordered_map<int,int>&mp){
        if(!root){
            return 0;
        }
        int lsum=dfs(root->left,mp);
        int rsum=dfs(root->right,mp);
        int currsum=lsum+rsum+root->val;
        mp[currsum]++;
        return currsum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>mp;
        dfs(root,mp);
        vector<int>ans;
        int mx=-1;
        for(auto &it:mp){
            mx=max(mx,it.second);
        }
        for(auto &it:mp){
            if(it.second==mx){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};