#include<iostream>
using namespace std;
#include<queue>
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
void levelorder(TreeNode* root){

    if(root==NULL)
        return;

    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()){

        TreeNode* curr=q.front();
        q.pop();

        cout<<curr->val<<" ";

        if(curr->left)
            q.push(curr->left);

        if(curr->right)
            q.push(curr->right);
    }
}