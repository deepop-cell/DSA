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
typedef long long ll;
int dfs(TreeNode* root,unordered_map<long long,int>&sum){
    if(!root){
        return 0;
    }
    ll lsum=dfs(root->left,sum);
    ll rsum=dfs(root->right,sum);
    ll currsum=lsum+rsum+root->val;
    sum[currsum]++;
    return currsum;
}
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<long long,int>sum;//ye sum and uski freq store krega
        dfs(root,sum);
        int mxfreq=-1;
        for(auto it:sum){
        mxfreq=max(mxfreq,it.second);
        }
        vector<int>ans;
        for(auto &it:sum){
            if(it.second==mxfreq){
                ans.push_back(it.first);
            }
        }
        return ans;
        
    }
};