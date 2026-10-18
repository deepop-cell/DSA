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
    int maxidx(vector<int>&nums,int low,int high){
        int mx=-1;
        int idx=-1;
        for(int i=low;i<=high;i++){
            if(nums[i]>mx){
                mx=nums[i];
                idx=i;
            }
        }
        return idx;
    }
    TreeNode* buildtree(vector<int>&nums,int left,int right){
        if(left>right){
            return NULL;
        }
        int idx=maxidx(nums,left,right);
        TreeNode * root=new TreeNode(nums[idx]);
        root->left=buildtree(nums,left,idx-1);
        root->right=buildtree(nums,idx+1,right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildtree(nums,0,nums.size()-1);
    }
};