#include<iostream>
using namespace std;
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
void Preordertraversal(TreeNode * root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    Preordertraversal(root->left);
    Preordertraversal(root->right);
}