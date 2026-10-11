
class Solution {
public:
bool isleaf(TreeNode * r){
    if(r && !r->left && !r->right){
        return true;
    }
    return false;
}
bool ispath(TreeNode* root,TreeNode * target,vector<TreeNode*>&path){
    if(!root){
        return false;
    }
    path.push_back(root);
    if(root==target){
        return true;
    }
    bool searchleft=ispath(root->left,target,path);
    if(searchleft){
        return true;
    }
    bool searchright=ispath(root->right,target,path);
    if(searchright){
        return true;
    }
    path.pop_back();
    return false;
}
    int countPairs(TreeNode* root, int distance) {
        int cnt=0;
        unordered_map<TreeNode*,int>depth;
        depth[root]=0;
        queue<TreeNode*>q;
        q.push(root);
        vector<TreeNode*>leaf;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto it=q.front();
                q.pop();
                if(isleaf(it)){
                    leaf.push_back(it);
                }
                if(it->left){
                    q.push(it->left);
                    depth[it->left]=depth[it]+1;
                }
                if(it->right){
                    q.push(it->right);
                    depth[it->right]=depth[it]+1;
                }
            }
        }
        vector<vector<TreeNode*>>allpaths(leaf.size());
        for(int i=0;i<leaf.size();i++){
            vector<TreeNode*>path;
            ispath(root,leaf[i],path);
            allpaths[i]=path;
        }
        for(int i=0;i<leaf.size();i++){
            for(int j=i+1;j<leaf.size();j++){
                TreeNode* lca=NULL;
                for(int k=0;k<min(allpaths[i].size(),allpaths[j].size());k++){
                    if(allpaths[i][k]==allpaths[j][k]){
                        lca=allpaths[i][k];
                    }
                    else{
                        break;
                    }
                }
                //ab inke beech ka dist hai deptha+depthb-2*dpeth(lca).
                int dist=depth[leaf[i]]+depth[leaf[j]]-2*depth[lca];
                if(dist<=distance){
                    cnt++;
                }
            }
        }
return cnt;
    }
};