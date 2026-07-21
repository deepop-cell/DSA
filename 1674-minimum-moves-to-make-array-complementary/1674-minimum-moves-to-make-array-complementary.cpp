class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>diff(2*limit+2,0);
        for(int i=0;i<n/2;i++){
            int a=nums[i];
            int b=nums[n-1-i];
            diff[2]+=2;
            diff[2*limit+1]-=2;
            //ab is pair se maxval aur min val kya bana skte wo find kro..
            int minval=1+min(a,b);//max of a,b ko convert krdo 1 mai and min bachgya
            int maxval=limit+max(a,b);//min ko limit mai convert krdo aur max bachgya.
            //now we have range[minva,maxval]. isme sare ke lie moves =1 lgega.. except when a+b = targetsum..
            //for moves=1;
            diff[minval]+=-1;
            diff[maxval+1]-=(-1);

            //for moves=0;
            diff[a+b]-=1;
            diff[a+b+1]-=(-1);//inko aur ek se ghata do taki intial 2 se ye 0 ho jaye because movesis 0 for them.
        }
            int result=INT_MAX;
            int csum=0;
            for(int target=2;target<=2*limit;target++){
                csum+=diff[target];
                diff[target]=csum;
                result=min(result,diff[target]);
            }
        return result;
    }
};