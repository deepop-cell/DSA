class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string,int>available;
        for(auto &x:bank){
            available[x]++;
        }
        unordered_map<string,bool>vis;
        vector<char>changes={'G','A','T','C'};
        queue<string>q;
        q.push(startGene);
        vis[startGene]=true;
        int moves=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                string curr=q.front();
                if(curr==endGene){
                    return moves;
                }
                q.pop();
                //we have 8 positions where at each we can do 4 options.
                for(int x=0;x<8;x++){
                    string New=curr;
                    char ch=curr[x];
                    //we can change ch to G,A,T,C.
                    for(auto &z:changes){
                        if(z==ch){
                            continue;
                        }
                        ch=z;
                        New[x]=ch;
                        if(available.find(New)==available.end() || vis[New]){
                            continue;
                        }
                        else{
                            vis[New]=true;
                            q.push(New);
                        }
                    }

                }

            }
            moves++;
        }
        return -1;
    }
};