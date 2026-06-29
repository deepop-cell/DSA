
class Solution {
public:
bool isOnepresent(TreeNode* root){
    if(root==NULL){
        return false;
    }
    if(root->val==1){
        return true;
    }
    else{
        return isOnepresent(root->left) || isOnepresent(root->right);//if right ya left ek mai bhi present hai ya nahi check karo.
    }
}
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        if(!isOnepresent(root->left)){//kya left mai one nahi hai
            root->left=NULL;//left ko null krdo delete krne ke lie
        }
        if(!isOnepresent(root->right)){
            root->right=NULL;
        }
        pruneTree(root->left);
        pruneTree(root->right);//recursive calls for left and right subtrees.
        if(root->left==NULL && root->right==NULL && root->val==0){// only 0 wala case.
            return NULL;
        }

        return root;
    }
};