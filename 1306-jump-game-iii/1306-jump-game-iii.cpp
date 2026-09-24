class Solution {
public:
    bool canReach(vector<int>& nums, int start) {
      //one way is dp way but it will give tle because it will requuire backtracking because we need to mark visited as well.
      //but we can do bfs 
      queue<int>q;
      int n=nums.size();
      q.push(start);
      vector<bool>vis(n,false);
      vis[start]=true;
      while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            int curr=q.front();
            q.pop();
            if(nums[curr]==0){
                return true;
            }
            if(nums[curr]+curr < nums.size()){
                //means we can go here/
                q.push(nums[curr]+curr);
                vis[nums[curr]+curr]=true;
            }
            if(curr-nums[curr]>=0 && !vis[curr-nums[curr]]){
                q.push(curr-nums[curr]);
                vis[curr-nums[curr]]=true;
            }
        }
      }  
      return false;
    }
};