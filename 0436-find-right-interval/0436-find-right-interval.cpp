class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<pair<int,int>,int>>as;
        for(int i=0;i<intervals.size();i++){
            as.push_back({{intervals[i][0],intervals[i][1]},i});
        }
        sort(as.begin(),as.end());
        vector<int>req(as.size(),-1);
        vector<int>starting(as.size());
        for(int i=0;i<as.size();i++){
            starting[i]=as[i].first.first;
        }
        for(int i=0;i<as.size();i++){
            int currentend=as[i].first.second;
            auto next=lower_bound(starting.begin(),starting.end(),currentend);
            if(next==starting.end()){
                continue;//nto found
            }
            int nextidx=next-starting.begin();
            req[as[i].second]=as[nextidx].second;
        }
        return req;
    }
};