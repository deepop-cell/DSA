class Solution {
public:
//LINE SWEEP TECHNIQUE
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>>events;
        for(auto &x:logs){
            int start=x[0];
            int end=x[1];
            events.push_back({start,1});
            events.push_back({end,-1});
        }
        sort(events.begin(),events.end());
        int currpop=0;
        int maxpop=INT_MIN;
        int maxyear=-1;
        for(int i=0;i<events.size();i++){
          int year=events[i].first;
          int delta=events[i].second;
          currpop+=delta;
          if(currpop>maxpop){
            maxpop=currpop;
            maxyear=year;
          }
        }
        return maxyear;
    }
};