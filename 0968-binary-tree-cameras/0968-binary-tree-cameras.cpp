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
//camera hai , covered hai 
    pair<bool,bool>dfs(TreeNode* root,int &cam){
        if(!root){
            return {false,true};
        }
        auto [La,Lb]=dfs(root->left,cam);
        auto [Ra,Rb]=dfs(root->right,cam);
        if( La || Ra ){
            //dono mai se ek par bhi camera hai . 
            if(La){
                //left pe cam hai 
                if(Rb){
                    //right covered hai 
                    //no need of cam here. 
                    //but ye covered hai due to left cam
                    return {false,true};
                }
                else if(!Rb){
                    //right covered nahi hai 
                    //to humein yaha par cam place krna hee padega 
                    cam++;
                    return {true,true};
                }
            }
            else if(Ra){
                //right pe cam hai . 
                if(Lb){
                    //left covered hai 
                    //no need of cam here 
                    // and current bhi  covered hai due to right cam 
                    return {false,true};
                }
                else if(!Lb){
                    //left covered nahi hai 
                    //yaha cam place krna padega 
                    cam++;
                    return {true,true};
                }
            }
        }
        if( Lb && Rb){
            //matlab kisi ek pe cam to nahi hai but dono hee covered hai so no need to place camera here.
            return {false,false};
        }
        if(!Rb || !Lb){
            //right covered nhi hai  ya to left covered nahi hai 
            cam++;
            return {true,true};
        }
        return {false,true};
    }
    int minCameraCover(TreeNode* root) {
        int cam=0;
        auto [x,y]=dfs(root,cam);
        if(!y){
            //root covered nahi hai 
            cam++;
        }
        return cam;
    }
};