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
    bool dfs(TreeNode* root, int final,string &s,unordered_map<TreeNode*,TreeNode*>&parent,unordered_map<TreeNode*,bool>&vis){
        vis[root]=true;
        if(root->val==final){
            return true;
        }
        //yaha se 3 jagaah ja skte hai , left , right and parent.
        if(root->left && !vis[root->left]){
            s.push_back('L');
            if(dfs(root->left,final,s,parent,vis))return true;
            else{
            s.pop_back();
            }
        }
        if(root->right && !vis[root->right]){
            s.push_back('R');
            if(dfs(root->right,final,s,parent,vis))return true;
            else{
            s.pop_back();
            }
        }
        if(parent[root] && !vis[parent[root]]){
            s.push_back('U');
            if(dfs(parent[root],final,s,parent,vis))return true;
            else{
            s.pop_back();
            }
        }
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
       unordered_map<TreeNode*,TreeNode*>parent;
       queue<TreeNode*>q;
       q.push(root);
       TreeNode* Shuruat=NULL;
       while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            TreeNode* curr=q.front();
            if(curr->val==startValue){
                Shuruat=curr;
            }
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
       //parents mark kr diye taaki har direction mai traverse kr ske now its just a  graph type shit.
       //now we will do bfs from start to end but with two states , one will be node and second will be string storing kya dirextions liya hia humne.
    //    queue<pair<TreeNode*,string>>q2;
    //    string path="";
    //    q2.push({Shuruat,path});
    //    unordered_map<TreeNode*,bool>vis;
    //    vis[Shuruat]=true;
    //    while(!q2.empty()){
    //     int sz=q2.size();
    //     for(int i=0;i<sz;i++){
    //         auto it=q2.front();
    //         q2.pop();
    //         TreeNode* node=it.first;
    //         string curr=it.second;
    //         if(node->val==destValue){
    //             return curr;
    //         }
    //         if(node->left && vis.find(node->left)==vis.end()){
    //             q2.push({node->left,curr + 'L'});
    //             vis[node->left]=true;
    //         }
    //         if(node->right && vis.find(node->right)==vis.end()){
    //             q2.push({node->right,curr + 'R'});
    //             vis[node->right]=true;
    //         }
    //         if(parent[node] && vis.find(parent[node])==vis.end()){
    //             q2.push({parent[node],curr + 'U'});
    //             vis[parent[node]]=true;
    //         }
    //     }
    //    }
    //    return "";
//but usse MLE aa gya to dfs se backtracking se krenge
string s="";
unordered_map<TreeNode*,bool>vis;
vis[Shuruat]=true; 
 dfs(Shuruat,destValue,s,parent,vis);
 return s;
    }
};