class Solution {
public:
    int countbits(int n){
        int cnt=0;
        while(n>0){
            if(n&1==1){
                cnt++;
            }
            n>>=1;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
       vector<pair<int,int>>p;
       for(int i=0;i<arr.size();i++){
        int cnt=countbits(arr[i]);
        p.push_back({cnt,arr[i]});
       }
       sort(p.begin(),p.end());
       vector<int>ans;
       for(int i=0;i<p.size();i++){
        ans.push_back(p[i].second);
       }
       return ans;
    }
};