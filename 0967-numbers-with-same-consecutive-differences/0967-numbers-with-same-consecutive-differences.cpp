class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        int check=1;
        for(int i=1;i<=n;i++){
            check*=10;
        }
        int lowercheck=check/10;
        //so its like bfs only we hve neighbours wo have difference lesser than k. 
        queue<long long >q;
        for(int i=1;i<=9;i++){
            q.push(i);
        }
        vector<vector<int>>adj(11);
        for(int i=0;i<=9;i++){
            //ab is i ke lie dekho
            for(int j=i;j<=9;j++){
                if(abs(i-j)==k){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        unordered_set<long long>st;
        while(!q.empty()){
            long long curr=q.front();
            q.pop();
            if(curr<check && curr>=lowercheck){
                st.insert(curr);
            }
            //now we have to append every possible where abs diff is exactly k.
            for(auto &v:adj[curr%10]){
                long long newcurr=1LL * curr*10+v;
                if(newcurr<check){
                    q.push(newcurr);
                }
            }
        }
        vector<int >ans(st.begin(),st.end());
        return ans;
    }
};