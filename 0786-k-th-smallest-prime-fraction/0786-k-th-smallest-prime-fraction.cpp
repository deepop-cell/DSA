class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        int i=0;
        int j=n-1;
        priority_queue<pair<double,pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
            double fr=(1.0*arr[i])/arr[j];
            pq.push({fr,{arr[i],arr[j]}});
            if(pq.size()>k){
                pq.pop();
            }
            }

        }
       return {pq.top().second.first,pq.top().second.second};
    }
};