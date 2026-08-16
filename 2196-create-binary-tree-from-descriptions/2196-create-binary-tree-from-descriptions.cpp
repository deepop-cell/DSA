
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int>st;
        unordered_map<int,TreeNode*>mp;
        for(int i=0;i<descriptions.size();i++){
            st.insert(descriptions[i][1]);
        }//all the children
        int rootval;
        for(int i=0;i<descriptions.size();i++){
            if(st.find(descriptions[i][0])==st.end()){   //nt found in set of children
            rootval=descriptions[i][0];
        }
        }
        for(auto &d:descriptions){
            int parent=d[0];
            int child=d[1];
            int isleft=d[2];
            if(mp.find(parent)==mp.end()){
                mp[parent]=new TreeNode(parent);
            }
            if(mp.find(child)==mp.end()){
                mp[child]=new TreeNode(child);
            }
            if(isleft){
                mp[parent]->left=mp[child];
            }
            else{
                mp[parent]->right=mp[child];
            }
        }

        return mp[rootval];
    }
};