
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
            TreeNode* curr=q.front();

            if(i==sz-1){
                ans.push_back(curr->val);
            }
            q.pop();
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