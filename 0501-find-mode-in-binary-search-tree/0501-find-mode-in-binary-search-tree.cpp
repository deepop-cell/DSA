class Solution {
public:
    void dfs(TreeNode* root, vector<int>& inorder) {
        if (root == NULL) return;
        
        dfs(root->left, inorder);
        inorder.push_back(root->val);
        dfs(root->right, inorder);
    }

    vector<int> findMode(TreeNode* root) {
        if (root == NULL) return {};
        
        vector<int> inorder;
        dfs(root, inorder);
        
        vector<int> result_modes;
        int maxfreq = 0;
        int freq = 0;
        int current_val = inorder[0];
        
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == current_val) {
                freq++; // Increment streak for current value
            } else {
                current_val = inorder[i]; // New value encountered
                freq = 1;                 // Reset streak to 1
            }
            
            // Check if our current streak breaks a record or ties it
            if (freq > maxfreq) {
                maxfreq = freq;
                result_modes.clear(); // Found a higher frequency; clear previous modes
                result_modes.push_back(current_val);
            } else if (freq == maxfreq) {
                result_modes.push_back(current_val); // It's a tie!
            }
        }
        
        return result_modes;   
    }
};