
class Solution {
public:
void inorder(TreeNode* root,vector<int>&inorderT){
    if(root==NULL){
        return;
    }
    inorder(root->left,inorderT);
    inorderT.push_back(root->val);
    inorder(root->right,inorderT);
}
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int>inorderT;
        inorder(root,inorderT);
        int i=0;
        while(i<inorderT.size() && inorderT[i]<low){
            i++;
        }
        long long ans=0;
        while( i<inorderT.size() && inorderT[i]<=high){
            ans+=inorderT[i];
            i++;
        }
       

     return ans;
        
    }
};