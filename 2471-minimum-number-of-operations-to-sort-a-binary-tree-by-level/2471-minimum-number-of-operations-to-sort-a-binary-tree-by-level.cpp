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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int>level;
            for(int i=0;i<sz;i++){
                auto curr=q.front();
                q.pop();
                level.push_back(curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            ans.push_back(level);
        }
        int swaps=0;
        for(int i=0;i<ans.size();i++){
        unordered_map<int,int>mp;
        vector<int>temp=ans[i];
        sort(temp.begin(),temp.end());
        for(int j=0;j<temp.size();j++){
            mp[temp[j]]=j;
        }
        //now count swaps needed.
        for(int j=0;j<ans[i].size();j++){
            while(ans[i][j]!=ans[i][mp[ans[i][j]]]){
                swap(ans[i][j],ans[i][mp[ans[i][j]]]);
                swaps++;
            }
        }
        }
        return swaps;
    }
};