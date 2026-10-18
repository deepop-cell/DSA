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
   bool isleaf(TreeNode* root){
    return  root && !root->right && !root->left ;
   }
   void bfs(TreeNode* root,queue<pair<TreeNode*,string>>&q2){
queue<TreeNode*>q;
      q.push(root);
      while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            auto curr=q.front();
            if(isleaf(curr)){
               q2.push({curr, string(1, char('a' + curr->val))});
            }
            q.pop();
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
      }
   }
    string smallestFromLeaf(TreeNode* root) {
      unordered_map<TreeNode* , TreeNode*>parent;
      queue<TreeNode*>q;
      q.push(root);
      while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            auto curr=q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
                parent[curr->left]=curr;
            }
            if(curr->right){
                q.push(curr->right);
                parent[curr->right]=curr;
            }
        }
      }
      vector<string>res;
      queue<pair<TreeNode*,string>>q2;
      //first push all the leaf in the queue.
      bfs(root,q2);
      while(!q2.empty()){
        int sz=q2.size();
        for(int i=0;i<sz;i++){
            auto it=q2.front();
            q2.pop();
            auto curr=it.first;
            auto currstring=it.second;
            if(parent.find(curr)!=parent.end()){
               q2.push({parent[curr], currstring + char('a' + parent[curr]->val)});
            }
            else{
                //iska koi parent nhi hai (means root aa gya hai ).
                //just simplu push in resz
                res.push_back(currstring);
            }
        }
      }
      sort(res.begin(),res.end());
      return res[0];
    }
};