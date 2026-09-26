class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_map<int,bool>mp;
        for(int i=0;i<forbidden.size();i++){
            mp[forbidden[i]]=true;
        }
        queue<pair<int,bool>>q;
        //we will do bfs with 2 states , what pos and prev jump was back or not
        int dist=0;
        q.push({0,false});
        unordered_map<int,bool>vis_forward;
        unordered_map<int,bool>vis_backward;
        vis_forward[0]=true;
        vis_backward[0]=true;
        bool found=false;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto it=q.front();
                q.pop();
                int pos=it.first;
                if(pos==x){
                    return dist;
                }
                bool back=it.second;
                int next1=pos+a;
                int next2=pos-b;
                if(next1<=8000 && mp.find(next1)==mp.end() && vis_forward.find(next1)==vis_forward.end()){
                    //not forbidden.
                    q.push({next1,false});
                    vis_forward[next1]=true;
                }
                if(next2>=0 && mp.find(next2)==mp.end() && vis_backward.find(next2)==vis_backward.end() && !back){
                    q.push({next2,true});
                    vis_backward[next2]=true;     
                }
            }
            dist++;
        }
        return -1;
    }
};