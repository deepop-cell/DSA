class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        vector<int>next_filled(n,-1);
        vector<int>prev_filled(n,n);
        int prev=-1;
        int next=-1;
        if(seats[0]==1){
            prev=0;
        }
        if(seats[n-1]==1){
            next=n-1;
        }
        for(int i=1;i<n;i++){
            if(seats[i]==1){
                prev=i;
            }
            else{
            prev_filled[i]=prev;
            }
        }
        for(int i=n-2;i>=0;i--){
        if(seats[i]==1){
            next=i;
        }
        else{
            next_filled[i]=next;
        }
        }
        //now traverse in seats.
        int mx_distance=INT_MIN;
        for(int i=0;i<n;i++){
            if(seats[i]==1 ){
                continue;
            }
            int dist=abs(min(abs(next_filled[i]-i),abs(i-prev_filled[i])));
           
            mx_distance=max(mx_distance,dist);
        }
        return mx_distance;
    }
};