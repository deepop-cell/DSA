
class Solution {
public:
    void dfs(TreeNode * root,unordered_set<int>&st){
        if(!root){
            return ;
        }
        dfs(root->left,st);
        dfs(root->right,st);
        st.insert(root->val);
    }
    int findSecondMinimumValue(TreeNode* root) {
        unordered_set<int>st;
        dfs(root,st);
        if(st.size()<2){
            return -1;
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &s:st){
            pq.push(s);
        }
        pq.pop();
        return pq.top();
    }
};