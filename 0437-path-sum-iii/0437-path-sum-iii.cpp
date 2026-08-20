//second way to do it.(o(n)).
class Solution {
public:
void dfs(TreeNode* root,unordered_map<long long ,int>&mp,long long currsum,int targetsum,int &paths){
    if(!root){
        return;
    }
    currsum+=root->val;
    if(mp.find(currsum-targetsum)!=mp.end()){
        paths+=mp[currsum-targetsum];
    }
        mp[currsum]++;
        dfs(root->left,mp,currsum,targetsum,paths);
        dfs(root->right,mp,currsum,targetsum,paths);
        mp[currsum]--;//baxktracking.(undo).
}
    int pathSum(TreeNode* root, int targetSum) {
        int ways=0;
        unordered_map<long long,int>mp;
        mp[0]=1;
        dfs(root,mp,0,targetSum,ways);
        return ways;
    }
};