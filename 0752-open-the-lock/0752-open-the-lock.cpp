class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        //so we have diffeent states so we cna do bfs 
        string start="0000";
        queue<string>q;
        q.push(start);
        int level=0;
        unordered_map<string,bool>vis;
        unordered_map<string,bool>laude;
        for(auto &s:deadends){
            laude[s]=true;
        }
        if(laude.find(start)!=laude.end()){
            return -1;
        }
        vis[start]=true;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                string curr=q.front();
                if(curr==target){
                    return level;
                }
                q.pop();
                for(int j=0;j<=3;j++){
                  string n1 = curr;
                  string n2=curr;
                  char ch=n1[j];
                  char ch1=((ch)-'0' +  1)%10 + '0';
                  char ch2=( ch - '0' - 1 + 10 )%10 + '0';
                  n1[j]=ch1;
                  n2[j]=ch2;
                  if(!vis[n1] && laude.find(n1)==laude.end()){
                    q.push(n1);
                    vis[n1]=true;
                  }
                  if(!vis[n2] && laude.find(n2)==laude.end()){
                    q.push(n2);
                    vis[n2]=true;
                  }

                }
            }
            level++;
        }
        return -1;
    }
};