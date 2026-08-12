class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        //see its like a graph question, we have sytates and the one shaving only one digit shift is neighbour and if dead end then its not visotable, and we need to find bfs from 0000 to target.
         vector<bool>vis(10000,false);
         for(string &x:deadends){
            int z=stoi(x);
            vis[z]=true;
         }
         if(vis[0]){
            //agar startingf hee deadend hua to khtm h khel.
            return -1;
         }
         if(target=="0000"){
            return 0;
         }
        queue<string>q;
        q.push("0000");
        int level=0;
        bool reached=false;
        while(!q.empty()){
            int sz=q.size();//size  of current level.
            for(int i=0;i<sz;i++){
            string curr=q.front();
            if(curr==target){
                return level;
            }
            q.pop();
            for(int j=0;j<=3;j++){
                string movedahead=curr;
                string movedbehind=curr;
                char c=movedahead[j];
                char d=movedbehind[j];
                // now lets to moveahead.
                c=(c=='9')?'0':c+1;
                movedahead[j]=c;
                int idx1=stoi(movedahead);
                if(!vis[idx1]){
                    q.push(movedahead);
                    vis[idx1]=true;
                }

                //now lets move behind.
                d=(d=='0')?'9':d-1;
                movedbehind[j]=d;
                int idx2=stoi(movedbehind);
                if(!vis[idx2]){
                    q.push(movedbehind);
                    vis[idx2]=true;
                }
            }
            }
            level++;
        }
    //agar queue ke andar se kabhi return nhi hhua matlab non reahcable h. 
    return -1;
    }
};