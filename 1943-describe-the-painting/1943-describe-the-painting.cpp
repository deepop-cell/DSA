class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<long long,long long>mp;
        for(auto &x:segments){
            long long start=x[0];
            long long end=x[1];
            long long col=x[2];
            mp[start]+=col;
            mp[end]-=col;
        }
        //
        vector<vector<long long>>ans;
        auto it=mp.begin();
        auto it2=mp.begin();
        it2++;
        long long csum=0;
        while(it2!=mp.end()){
            csum+=it->second;
            if(csum>0){
            ans.push_back({it->first,it2->first,csum});
            }

            it++;
            it2++;
        }
        return ans;
    }
};