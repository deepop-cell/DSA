class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n=nums.size();
       unordered_map<int,vector<int>>mp;
       for(int i=0;i<nums.size();i++){
        mp[nums[i]].push_back(i);
       } 
       int steps=0;
       queue<int>q;
       q.push(0);
       bool found=false;
       vector<bool>vis(n,false);
       while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            int curr=q.front();
            q.pop();
            if(curr==n-1){
                found=true;
                break;
            }
            //now igt has 3 possible neughbours
            if(curr+1<n && !vis[curr+1]){//aaage
                q.push(curr+1);
                vis[curr+1]=true;
            }
            if(curr-1>=0 && !vis[curr-1]){//peeche
                q.push(curr-1);
                vis[curr-1]=true;
            }
            //equal wale index pe 
            for(auto &x:mp[nums[curr]]){
                if(!vis[x]){
                    q.push(x);
                    vis[x]=true;
                }
                mp[nums[curr]].clear();//ye wale process ho gaye to inko uda do wrna baar baar process honge aur tle denge
            }
        }
        if(found){
            return steps;
        }
        steps++;
       }
       return 0;
    }
};