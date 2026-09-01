class Solution {
public:
//LiNe Sweeep algorithm
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       vector<pair<int,int>>events;
       for(auto & x:trips){
        int num=x[0];
        int start=x[1];
        int end=x[2];
        events.push_back({start,num});
        events.push_back({end,-1 * num});
       } 
       sort(events.begin(),events.end());
       //now traverse in events and check if at any time no of passengers are greater than capacity or not.
       int curr=0;
       for(int i=0;i<events.size();i++){
        int delta=events[i].second;
        curr+=delta;
        if(curr>capacity){
            return false;
        }
       }
       return true;
    }
};