
class Solution {
public:
    TreeNode* deleteHelper(TreeNode* root,unordered_set<int>&st,vector<TreeNode*>&result){
        if(root==NULL){
            return NULL;
        }
        //go left ( niche jao pehle)
        root->left=deleteHelper(root->left,st,result);
        root->right=deleteHelper(root->right,st,result);
        //ab niche aa chuka hoo.
        //check krunga ki ab delete krna hai ya nahi.
        if(st.find(root->val)!=st.end()){//delete krna  hai
            if(root->left){
            result.push_back(root->left);
            }
            if(root->right){
                result.push_back(root->right);
            }
            delete root;
            return NULL;
        }
        else{//delete nahi krna hai
        return root;

        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>result;
        unordered_set<int>st;
        for(int &nums : to_delete){
            st.insert(nums);
        }
        if(st.find(root->val)==st.end()){
            result.push_back(root);
        }
        deleteHelper(root,st,result);
        return result;
    }
};