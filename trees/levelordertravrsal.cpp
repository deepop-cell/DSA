#include<iostream>
struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};
int max(int x,int y){
    return (x>y)?x:y;
}
int treehight(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(treehight(root->left),treehight(root->right));
}
void printlevel(TreeNode* root,int level){
    if(root==NULL){
        return;
    }
    if(level==1){
        std::cout<<root->val<<" ";
        return;
    }
    printlevel(root->left,level-1);
    printlevel(root->right,level-1);

}
void levelorder(TreeNode* root){
    int height=treehight(root);
    for(int i=1;i<=height;i++){
        printlevel(root,i);
    }
}
// this is o(n*n) solution , hence not optimal.