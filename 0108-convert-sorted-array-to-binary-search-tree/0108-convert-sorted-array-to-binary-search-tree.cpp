
class Solution {
public:
TreeNode* helper(int low,int high,vector<int>&nums){
    if(low>high){
        return nullptr;
    }
    int mid=(low+(high-low)/2);
    //isko mid ko root bana do ..
    TreeNode* root= new TreeNode(nums[mid]);
    root->left=helper(low,mid-1,nums);
    root->right=helper(mid+1,high,nums);
    return root;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return helper(0,nums.size()-1,nums);
        
    }
};