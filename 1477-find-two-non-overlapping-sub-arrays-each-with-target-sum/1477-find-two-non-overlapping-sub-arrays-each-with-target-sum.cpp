class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int target) {
    int n=nums.size();
    priority_queue<int>pq;
    vector<pair<int,int>>subarrays;//stores the starting and ending of each subarray which equals sum target;
    int l=0;
    long long sum=0;
    for(int r=0;r<n;r++){
        sum+=nums[r];
        while(sum>target){
            sum-=nums[l];
            l++;
        }
        //now we have a valid window.
        if(sum==target){
            subarrays.push_back({l,r});
            pq.push(r-l+1);
            if(pq.size()>2){
                pq.pop();
            }
        }

    }
    if(pq.size()<2){
        return -1;
    }
    sort(subarrays.begin(),subarrays.end());
    vector<int>starting(subarrays.size());
    for(int i=0;i<starting.size();i++){
        starting[i]=subarrays[i].first;
    }
    int mn=INT_MAX;
    vector<int>min_after(subarrays.size());
    int z=subarrays[subarrays.size()-1].second-subarrays[subarrays.size()-1].first+1;
    min_after[min_after.size()-1]=z;
    for(int i=min_after.size()-2;i>=0;i--){
        z=min(z,subarrays[i].second-subarrays[i].first+1);
        min_after[i]=z;
    }
    for(int i=0;i<subarrays.size();i++){
        //we are at current interval. now we wanna find the next index where the starting is greater than thr endingof cureent.
        //ye find is the index/
        int find=upper_bound(starting.begin(),starting.end(),subarrays[i].second)-starting.begin();
        if(find<subarrays.size()){
        int size1=subarrays[i].second-subarrays[i].first+1;
        int size2=min_after[find];
        mn=min(mn,size1+size2);
        }
    }
    return (mn>2*nums.size())?-1:mn;
    }
};