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
    //size , height , bool
    pair<int,pair<int,bool>> dfs(TreeNode* root,unordered_map<int,int>&mp){
        if(!root){
            return {0,{0,true}};
        }
        auto left=dfs(root->left,mp);
        auto right=dfs(root->right,mp);
        if(left.second.second && right.second.second){
            //dono side perfect BT hai(individually) 
            int leftheight=left.second.first;
            int rightheight=right.second.first;
            if(leftheight== rightheight){
                //same hieght hai  means all children are at same level.
                //this means ki ye jo root pe rooted subtree hai ye bhi perfect hai . 
                int leftsum=left.first;
                int rightsum=right.first;
                mp[leftsum+rightsum + 1]++;
                return {leftsum+rightsum+1,{1+leftheight,true}};
            }
            else{
                //true nhi hai to farak b nhi padta kuch bhi return krado . 
                return {0,{0,false}};
            }
        }
     return {0,{0,false}};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        unordered_map<int,int>mp;
        dfs(root,mp);
        vector<int>ans;
        for(auto &it:mp){
            for(int i=0;i<it.second;i++){
                ans.push_back(it.first);//freq b mattter krti hai 
            }
        }
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        if(ans.size()<k){
            return -1;
        }
        return ans[k-1];
    }
};