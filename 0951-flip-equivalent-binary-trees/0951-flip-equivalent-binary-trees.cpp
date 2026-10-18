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
    void bfs(TreeNode* root,unordered_map<int,vector<int>>&mp){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto curr=q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                    mp[curr->val].push_back(curr->left->val);
                }
                if(curr->right){
                    q.push(curr->right);
                    mp[curr->val].push_back(curr->right->val);
                }
            }
        }
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2){
            return true;
        }
        if(!root1 || !root2){
            return false;
        }
        if(!root1->left && !root1->right && !root2->left && !root2->right){
            return root1->val == root2->val;
        }
        if((!root1->left && !root1->right )|| (!root2->left && !root2->right)){
            return false;
        }
        unordered_map<int,vector<int>>mp1;
        unordered_map<int,vector<int>>mp2;
        bfs(root1,mp1);
        bfs(root2,mp2);
        for(auto &it :mp1){
            int curr=it.first;
            vector<int>a(it.second.begin(),it.second.end());
            vector<int>b(mp2[curr].begin(),mp2[curr].end());
            sort(a.begin(),a.end());
            sort(b.begin(),b.end());
            if(a.size()!=b.size()){
                return false;
            }
            for(int i=0;i<a.size();i++){
                if(a[i]!=b[i]){
                    return false;
                }
            }
        }
        return true;
        
    }
};