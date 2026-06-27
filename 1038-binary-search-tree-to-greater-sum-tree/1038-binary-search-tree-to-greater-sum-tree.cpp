
class Solution {
public:
    void dfsmaking(TreeNode* root,vector<int>&inorder){
        if(root==NULL){
            return;
        }
        dfsmaking(root->left,inorder);
        inorder.push_back(root->val);
        dfsmaking(root->right,inorder);
    }
    void dfstraversal(TreeNode* root,stack<int>&st){
        if(root==NULL){
            return;
        }
        dfstraversal(root->left,st);
        root->val=st.top();
        st.pop();
        dfstraversal(root->right,st);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>inorder;
        dfsmaking(root,inorder);
        stack<int>st;
        for(int i=inorder.size()-1;i>=0;i--){
            if(st.empty()){
                st.push(inorder[i]);
            }
            else{
                st.push(st.top()+inorder[i]);
            }
        }
        dfstraversal(root,st);
        return root;

    }
};