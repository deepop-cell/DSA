class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int>st;//freq
        unordered_map<int,int>mp;
        for(int x:arr){
            mp[x]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            if(st.find(it->second)!=st.end()){
                return false;
            }
            st.insert(it->second);
        }
        return true;
        
    }
};