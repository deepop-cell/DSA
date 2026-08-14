class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n=watchedVideos.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<friends.size();i++){
            for(int &x:friends[i]){
                adj[i].push_back(x);
            }
        }
        queue<int>q;
        vector<int>vis(n,false);
        q.push(id);
        vis[id]=true;
        int y=0;
        vector<string>ans;
        while(!q.empty()){//bfs 
            int sz=q.size();
            if(y==level){
                for(int i=0;i<sz;i++){
                    int curr=q.front();
                    q.pop();
                    for(auto &z:watchedVideos[curr]){
                     ans.push_back(z);
                    }
                }
                break;
            }
            for(int i=0;i<sz;i++){
                int curr=q.front();
                q.pop();
                for(auto &v:adj[curr]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v]=true;
                    }
                }
            }
            y++;
        }
        //now we have our answer array where we have cbc for the first test case.
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
        map<string,int>mp;
        for(int i=0;i<ans.size();i++){
            mp[ans[i]]++;
        }
        for(auto &it:mp){
            pq.push({it.second,it.first});
        }
        //now priority q has in decrreasing order
        vector<string>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};