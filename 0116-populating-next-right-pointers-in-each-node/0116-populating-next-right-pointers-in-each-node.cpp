
class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return root;
        }
        queue<Node*>q;
        q.push(root);
        vector<vector<Node*>>ans;
        while(!q.empty()){
            int sz=q.size();
         vector<Node*>level;
           for(int i=0;i<sz;i++){
            Node* curr=q.front();
            q.pop();
            level.push_back(curr);
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
           }
           ans.push_back(level);
        }
        for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[i].size();j++){
                    if(j==ans[i].size()-1){
                        ans[i][j]->next=NULL;
                    }
                    else{
                        ans[i][j]->next=ans[i][j+1];
                    }
                }
        }
        return root;
    }
};