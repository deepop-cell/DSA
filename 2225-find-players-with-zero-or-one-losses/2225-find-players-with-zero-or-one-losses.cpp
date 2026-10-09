class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>win;
        unordered_map<int,int>lost;
        unordered_set<int>st;
        for(auto &x:matches){
            int a=x[0];
            int b=x[1];
            win[a]++;
            lost[b]++;
            st.insert(a);
            st.insert(b);
        }
        vector<int>winners;
        vector<int>losers;
        for(auto &s:st){
            if(lost.find(s)==lost.end()){
                //means ye hara to nahi hai .
                winners.push_back(s);
            }
            if(lost.find(s)!=lost.end()){
                //means atleast ek baar yo hara hai ye .
                if(lost[s]==1){
                    losers.push_back(s);
                }
            }
        }
        sort(winners.begin(),winners.end());
        sort(losers.begin(),losers.end());
        vector<vector<int>>ans;
        ans.push_back(winners);
        ans.push_back(losers);
        return ans;
    }
};