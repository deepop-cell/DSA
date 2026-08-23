/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
                parent[curr->left]=curr;
            }
            if(curr->right){
                q.push(curr->right);
                parent[curr->right]=curr;
            }
            }
        }
        //now we will do bfs from target node.
        queue<TreeNode*>q2;
        unordered_map<TreeNode*,bool>vis;
        vis[target]=true;
        q2.push(target);
        while(!q2.empty() && k>0){
            int sz=q2.size();
            for(int i=0;i<sz;i++){
                TreeNode* curr=q2.front();
                q2.pop();
                if(curr->left && !vis[curr->left]){
                    q2.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right]){
                    q2.push(curr->right);
                    vis[curr->right]=true;
                }
                if(parent.find(curr)!=parent.end() && !vis[parent[curr]]){
                    q2.push(parent[curr]);
                    vis[parent[curr]]=true;
                }
            }
            k--;// ek level ke baad.
        }
        vector<int>ans;
        while(!q2.empty()){
            ans.push_back(q2.front()->val);
            q2.pop();
        }
        return ans;
    }
};