/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

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
            vector<Node*>level;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                Node* curr=q.front();
                level.push_back(q.front());
                q.pop();
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
            for(int j=0;j<ans[i].size()-1;j++){
                ans[i][j]->next=ans[i][j+1];
            }
        }
        return root;
    }
};