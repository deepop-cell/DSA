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
void bfs(TreeNode* root,int &sum,int &count){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int sz=q.size();
        count+=sz;
        for(int i=0;i<sz;i++){
            TreeNode* curr=q.front();
            q.pop();
            sum+=curr->val;
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
}
    int averageOfSubtree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            TreeNode* curr=q.front();
            q.pop();
            int sum=0;
            int count=0;
            bfs(curr,sum,count);
            if(sum/count==curr->val){
            ans++;
            }
            sum+=curr->val;
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
    return ans;
    }
};