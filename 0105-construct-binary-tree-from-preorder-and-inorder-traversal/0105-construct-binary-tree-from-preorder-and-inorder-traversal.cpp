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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()){
            return nullptr;
        }
        //pehle hashmap banalo
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=new TreeNode(preorder[0]);//preorder ka 1st thing root hota hai na
        //now find this root in inorder trvaersal.
        int idx=mp[preorder[0]];
        //inorder= L,ROOT,RIGHT.. to jo idx aya hai uske pehle tk ka hai belinging to leftsubtree and uske baad ka jo hai its belongiing to rightsubtree.
        int leftsubtree=idx;
        int rightsubtree=inorder.size()-idx-1;
        vector<int>leftinorder;
        vector<int>leftpreorder;
        vector<int>rightinorder;
        vector<int>rightpreorder;
        for(int i=0;i<idx;i++){
            leftinorder.push_back(inorder[i]);
        }
        for(int i=idx+1;i<inorder.size();i++){
            rightinorder.push_back(inorder[i]);
        }
        for(int i=1;i<=leftsubtree;i++){
            leftpreorder.push_back(preorder[i]);
        }
        for(int i=leftsubtree+1;i<preorder.size();i++){
            rightpreorder.push_back(preorder[i]);
        }
        root->left=buildTree(leftpreorder,leftinorder);
        root->right=buildTree(rightpreorder,rightinorder);
        return root;
    }
};