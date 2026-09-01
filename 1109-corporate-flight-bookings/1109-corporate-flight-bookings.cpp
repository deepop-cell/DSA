class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
       vector<int>diff(n+1,0);
       for(auto &x:bookings){
        int start=x[0];
        int end=x[1];
        int val=x[2];
        diff[start]+=val;
        if(end+1<n+1){
            diff[end+1]-=val;
        }
       }
       int csum=0;
       for(int i=1;i<diff.size();i++){
        csum+=diff[i];
        diff[i]=csum;
       }
       //diff i stores net change in the ith flight ie number of seats booked in ith flight.
       reverse(diff.begin(),diff.end());
       diff.pop_back();
       reverse(diff.begin(),diff.end()); 
       return diff;
    }
};