class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       priority_queue<pair<int,int>>pq;//maxheap,
       //num-->diff of abs of nums and x
       for(int &y:arr){
        pq.push({abs(y-x),y});
        if(pq.size()>k){
            pq.pop();
        }
       } 
       //now heap contains k closest elements to x.
       vector<int>ans;
       while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
};