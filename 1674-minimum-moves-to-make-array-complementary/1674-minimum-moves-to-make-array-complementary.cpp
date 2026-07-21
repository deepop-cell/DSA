class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int>diff(2*limit+2,0);
        int n=nums.size();
        for(int i=0;i<n/2;i++){
            int a=nums[i];
            int b=nums[n-1-i];
            int minval=1+min(a,b);
            int maxval=limit+max(a,b);

            //start to end tk +2 krna hai..(because else ke lie wo hi hai,.)
            diff[2]+=2;
            diff[2*limit+1]-=2;

            //ab jao for moves=1;
            diff[minval]+=(-1);
            diff[maxval+1]-=(-1);//inke lie 2 tha but ispar 1 hona chaiye so further reduced by 1.

            //ab for moves=0;
            diff[a+b]+=(-1);
            diff[a+b+1]-=(-1);
        }
        int res=INT_MAX;
            int csum=0;
        for(int target=2;target<=2*limit;target++){
            csum+=diff[target];
            diff[target]=csum;
            res=min(res,diff[target]);
        }
        return res;
    }
};