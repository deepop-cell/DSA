class Solution {
public:
    void dfs(TreeNode* root, vector<int>& inorder) {
        if (root == NULL) {
            return;
        }
        dfs(root->left, inorder);
        inorder.push_back(root->val);
        dfs(root->right, inorder);
    }
    
    TreeNode* maketree(int low, int high, const vector<int>& inorder) {
        if (low > high) {
            return NULL;
        }
        int mid = low + (high - low) / 2; 
        TreeNode* r = new TreeNode(inorder[mid]);
        r->left = maketree(low, mid - 1, inorder);
        r->right = maketree(mid + 1, high, inorder);
        return r;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        dfs(root, inorder);

        return maketree(0, inorder.size() - 1, inorder);
    }
};