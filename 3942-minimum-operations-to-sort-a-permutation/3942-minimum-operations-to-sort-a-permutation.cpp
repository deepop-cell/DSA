class Solution {
public:
    bool fn(vector<int>&nums,int &dips){
        int n=nums.size();
        for(int i=0;i<n;i++){
        if(nums[(i+1)%n]<nums[i]){
            dips++;
        }
        }
        return dips==1 || dips==(n-1);
    }
    bool sorted(vector<int>&nums){
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                return false;
            }
        }
        return true;
    }
    void leftrotate(vector<int>&nums){
        int n=nums.size();
        //left ortate by 1.
        int a=nums[0];
        vector<int>arr(nums.size());

        for(int i=1;i<n;i++){
            arr[i-1]=nums[i];
        }
        arr[n-1]=nums[0];
        nums=arr;
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int d=0;
        if(!fn(nums,d)){
            return -1;
        }
        //check if already sort 
        bool f=true;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]<nums[i]){
                f=false;
                break;
            }
        }
        if(f){
            return 0;
        }
        if(!f && n==2){
            return 1;
        }
        queue<pair<int,int>>q;
        // starting point and direction . 
        //0 means dec and 1 means inc 
        int indir=-1;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        //in dir decide kro .
        if(d==1){
            //inc array hai 
            indir=1;
        }
        else if(d==n-1){
            //dec arr hai 
            indir=0;
        }
        set<pair<int,int>>vis;
        vis.insert({mp[0],indir});
        q.push({mp[0],indir});
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto it=q.front();
                q.pop();
                int curr=it.first;
                int dir=it.second;
                if(curr==0 && dir==1){
                    //mil gai manzil
                    return level;
                }
                //we have two options to explore.
                //reverse 
                int idx=curr;
                int newcurr=n-1-idx;
                int newdir=1-dir;
                if(vis.find({newcurr,newdir})==vis.end()){
                    q.push({newcurr,newdir});
                    vis.insert({newcurr,newdir});
                }
                //rotate 
                int new_l=(idx-1+n)%n;
                //dir to same hee rhegi 
                if(vis.find({new_l,dir})==vis.end()){
                    q.push({new_l,dir});
                    vis.insert({new_l,dir});
                }

            }
            level++;
        }
        return 0;
    }
};