class Solution {
public:
typedef long long ll;
    bool isvalid(vector<int>&piles,int check,int h){
        ll time=0;
        for(int i=0;i<piles.size();i++){
            time+=(piles[i]+check-1)/check;
        }
        return time<=h;//threshold check/
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx=INT_MIN;
        for(int &x:piles){
            mx=max(mx,x);
        }
        int low=1;
        int high=mx;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isvalid(piles,mid,h)){
                ans=mid;
                high=mid-1;//minimise this (try to).
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};