class Solution {
public:
    bool canmake(vector<int>&bloomDay,int m , int k , int day){
        //day day par check krenge ki possible hai ya nahi..
        int count=0;
        int bouqets=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                //matalab us day tak wo bloom ho chuka hoga..
                count++;
                //check if one bouqet can be fromed now,.
                if(count==k){
                    bouqets++;
                    count=0;
                }
            }
            else{
                count=0;
            }
        }
        return bouqets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1ll*m*k>bloomDay.size()){
            return -1;
        }
        int low=INT_MAX;
        int high=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            low=min(low,bloomDay[i]);
            high=max(high,bloomDay[i]);
        }
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canmake(bloomDay,m,k,mid)){
                //try a smaller day then
                ans=mid;
                high=mid-1;
            }
            else{
                //cant make sufficient bouqets try a bigger day..
                low=mid+1;
            }
        }
        return ans;
    }
};