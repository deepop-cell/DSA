class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        //heap stores value and index as well.
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        priority_queue<pair<int,int>>maxheap;
        int l=0;
        int r=0;
        int mx=-1;
        for(r=0;r<n;r++){
            minheap.push({nums[r],r});
            maxheap.push({nums[r],r});
            while(abs(minheap.top().first-maxheap.top().first)>limit){
                //tab tk shrink kro left ko
                l++;
            while(minheap.top().second<l)
            minheap.pop();

            while(maxheap.top().second<l)
            maxheap.pop();
            }
            //now we have a vlid window
            mx=max(mx,r-l+1);
        }
        return mx;
    }
};