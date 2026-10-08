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
void inorder(TreeNode* root,vector<int>&ans){
    if(!root){
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>list1;
        vector<int>list2;
        inorder(root1,list1);
        inorder(root2,list2);
        //noww e have list 1 and list 2.
        int i=0;
        int j=0;
        vector<int>res;
        while(i<list1.size() && j<list2.size()){
            if(list1[i]<list2[j]){
                res.push_back(list1[i]);
                i++;
            }
            else if(list1[i]>list2[j]){
                res.push_back(list2[j]);
                j++;
            }
            else{
                //equal hai.
                res.push_back(list1[i]);
                res.push_back(list2[j]);
                i++;
                j++;
            }
        }
        while(i<list1.size()){
            res.push_back(list1[i]);
            i++;
        }
        while(j<list2.size()){
            res.push_back(list2[j]);
            j++;
        }
        return res;
    }
};