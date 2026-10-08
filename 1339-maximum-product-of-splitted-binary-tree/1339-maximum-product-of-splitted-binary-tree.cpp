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
 long long  mod=1e9+7;
class Solution {
public:
int dfs(TreeNode* root,unordered_map<TreeNode*,long long >&sum){
    if(!root){
        return 0;
    }
     long long l=dfs(root->left,sum);
     long long r=dfs(root->right,sum);
    //now we are at curr.
    long long total=l+r+root->val;
    sum[root]=total;
    return total;
}
void d(TreeNode* root,long long &mx,unordered_map<TreeNode*,long long >&sum,long long fullsum){
    if(!root){
        return;
    }
mx=max(mx,1LL*(sum[root]*(fullsum-sum[root])));
d(root->left,mx,sum,fullsum);
d(root->right,mx,sum,fullsum);
}
    int maxProduct(TreeNode* root) {
        unordered_map<TreeNode*,long long>sum;
        dfs(root,sum);
        long long mx=0;
        long long fullsum=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto curr=q.front();
                q.pop();
                fullsum+=(curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }

        }
        //now do dfs, and max currnodes map *(total-currnodes map)..
        d(root,mx,sum,fullsum);
        return mx % (mod);
    }
};