
class Solution {
public:
   // has cam , covered by cam , not covered by camera 
    tuple<bool,bool,bool> dfs(TreeNode* root,int &cam){
        //base case is for leaf ( we dont want leaf to have cvam because wo koi kaam ka nhi hoga so we assume leafs left and rigjht covered by camera )
        if(!root){
            return make_tuple(false,true,false);
        }
        auto [La,Lb,Lc]=dfs(root->left,cam);
        auto [Ra,Rb,Rc]=dfs(root->right,cam);
  if(La || Ra){
            //ek bhi child pe camera hai . 
            if(La){
                //left pe cam hai 
                if(Rb || Ra){
                    //right covered hai . ya to camera hai .
                    //no need of cam 
                    return make_tuple(false,true,false);
                }
                else if(!Rc){
                    ///right covered nahi hai .
                    //humein yaha pe camera place krna hee padega '
                    cam++;
                    return make_tuple(true,true,false);
                }
            }
            else if(Ra){
                //right pe camera hai . 
                if(Lb || La){
                    //left covered hai ya to camera hai . 
                     //no need of camera here. 
                     return make_tuple(false,true,false);
                }
                else if(!Lc){
                    //left covered nahi hai . / we need to place a cam here . 
                    cam++;
                    return make_tuple(true,true,false);
                }
            }
        }
        if(Lb && Rb){
            //both are covered by camera so no need of camera here . 
            return make_tuple(false,false,true);
        }
        if(Lc || Rc){
            //agar dono mai se ek bhi not covered by camera hai . 
            //we need to place a camera at root ..
            cam++;
            return make_tuple(true,true,false);
        }

    return make_tuple(false,true,false);
    }
    int minCameraCover(TreeNode* root) {
        if(root && !root->left && !root->right){
            return 1;
        }
        int cam=0;
       auto [x,y,z]=dfs(root,cam);
       if(z){
        //means root is not covered at the end 
        cam++;
       }
        return cam;
    }
};