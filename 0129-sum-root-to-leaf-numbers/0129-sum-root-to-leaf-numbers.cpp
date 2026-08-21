
class Solution {
public:
    void solve(TreeNode* root,int number,long long&sum){
        if(root->left==NULL && root->right==NULL){
            sum+=number;
            return;
        }
        //options h.
        if(root->left){
            solve(root->left,number*10+(root->left->val),sum);
        }
        if(root->right){
            solve(root->right,number*10+(root->right->val),sum);
        }
    }
    int sumNumbers(TreeNode* root) {
        long long sum=0;
        solve(root,root->val,sum);
        return sum;
    }
};