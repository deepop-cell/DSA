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
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int>level;
            for(int i=0;i<sz;i++){
                auto curr=q.front();
                q.pop();
                level.push_back(curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            ans.push_back(level);
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i].size()==1){
                if(ans[i][0]%2==i%2){
                    return false;
                }
            }
            if(i%2==0){
                //even level hai/
                for(int j=0;j<ans[i].size()-1;j++){
                    if(ans[i][j]%2==0 || ans[i][j+1]<=ans[i][j] || ans[i][ans[i].size()-1]%2==0){
                        return false;
                    }
                }
            }
            else{
                //odd level hai
                for(int j=0;j<ans[i].size()-1;j++){
                    if(ans[i][j]%2!=0 || ans[i][j+1]>=ans[i][j] || ans[i][ans[i].size()-1]%2!=0){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};