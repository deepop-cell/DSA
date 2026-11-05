class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        if(n==2){
            return abs(nums[0]-nums[1]);
        }
        int check=nums[0];
        bool e=true;
        for(int i=1;i<n;i++){
            if(nums[i]!=check)e=false;
        }
        if(e)return -1;
        bool d=true;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]<nums[i] || (i==0 && nums[i+1]==nums[i]))continue;
            else{
                d=false;
                break;
            }
        }
        if(d){
            long long a=nums[0];
            long long b=0;
            for(int i=1;i<n;i++){
                b+=nums[i];
            }
            return abs(a-b);
        }
        bool inc=true;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]>nums[i] || (i==n-2 && nums[i+1]==nums[i])){
                continue;
            }
            else{
                inc=false;
                break;
            }
        }
        if(inc){
            long long a=0;
            long long b=nums[n-1];
            for(int i=0;i<n-1;i++){
                a+=nums[i];
            }
            return abs(a-b);
        }
        int peak=-1;
        int dips=0;
        bool f=false;
        if(nums[1]>nums[0])f=true;
        for(int i=1;i<n;i++){
            if(f && i+1<n && nums[i+1]<nums[i]){
                dips++;
                f=!f;
            }
            if(!f && i+1<n && nums[i+1]>nums[i]){
                dips++;
                f=!f;
            }
        }
        if(dips>1){
            return -1;
        }
        for(int i=1;i<n-1;i++){
            if(nums[i]>=nums[i+1] && nums[i]>=nums[i-1]){
                if(peak!=-1){
                    if (i==peak+1 && nums[i]==nums[peak]) {
                        continue; 
                    }
                    return -1;
                }
                peak=i;
            }
        }
        
        if(peak==-1){
            return -1;
        }
        else{
            vector<long long>prefix(n);
            long long  csum=0;
            for(int i=0;i<n;i++){
                csum+=nums[i];
                prefix[i]=csum;
            }
            //ya to peak ko lelo ya to peak ko mat lo . 
            //check if option 1 is valid 
            bool validl=true;
            for(int i=0;i<peak-1;i++){
                if(nums[i+1]<=nums[i]){
                    validl=false;
                    break;
                }
            }
            long long option1=0;
            if(!validl)option1=LLONG_MAX;
            else{
            option1=abs(prefix[peak-1]-(prefix[n-1]-prefix[peak-1]));
            }
            bool valid2=true;
            for(int i=peak+1;i<n-1;i++){
                if(nums[i+1]>=nums[i]){
                    valid2=false;
                    break;
                }
            }
            if(!validl && !valid2)return -1;
            long long option2=abs(prefix[peak]-(prefix[n-1]-prefix[peak]));
            return min(option1,option2);
        }
        return 0;
    }
};