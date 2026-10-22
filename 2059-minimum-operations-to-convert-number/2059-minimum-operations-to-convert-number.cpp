class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        //we can and should do bfds here , dp wont work since it will invlove marking 
        queue<int>q;
        int level=0;
        int n=nums.size();
        q.push(start);
        vector<bool>vis(1001,false);
        vis[start]=true;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int curr=q.front();
                if(curr==goal){
                    return level;
                }
                q.pop();
                if(curr<0 || curr>1000){
                    continue;
                }
                for(int j=0;j<n;j++){
                    if( (curr+nums[j]==goal || (curr+nums[j]>=0 && curr+nums[j]<=1000 && !vis[curr+nums[j]]))){
                        q.push(curr+nums[j]);
                        if(curr+nums[j]!=goal)vis[curr+nums[j]]=true;
                    }
                    if( curr-nums[j]==goal ||(curr-nums[j]>=0 && curr-nums[j]<=1000 && !vis[curr-nums[j]]) ){
                        q.push(curr-nums[j]);
                       if(curr-nums[j]!=goal) vis[curr-nums[j]]=true;
                    }
                    if( (curr^nums[j])==goal || ((curr^nums[j])>=0 && (curr^nums[j])<=1000 && !vis[curr^nums[j]])){
                        q.push(curr^nums[j]);
                        if((curr^nums[j])!=goal)vis[curr^nums[j]]=true;
                    }
                }
            }
 level++;
        }
        return -1;
    }
};