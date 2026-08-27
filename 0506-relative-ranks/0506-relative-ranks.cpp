class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});
        }
        int rnk=1;
        vector<string>ans(score.size());
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int curridx=it.second;
            if(rnk==1){
                ans[curridx]="Gold Medal";
            }
            else if(rnk==2){
                ans[curridx]="Silver Medal";
            }
            else if(rnk==3){
                ans[curridx]="Bronze Medal";
            }
            else{
                ans[curridx]=to_string(rnk);
            }
            rnk++;
        }
        return ans;
    }
};