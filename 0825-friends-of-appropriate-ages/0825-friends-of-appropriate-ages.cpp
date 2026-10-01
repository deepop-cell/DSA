class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int,int>mp;
        for(auto &x:ages){
            mp[x]++;
        }
        int cnt=0;
        sort(ages.begin(),ages.end());
        for(int i=0;i<ages.size();i++){
            int search=0.5*(ages[i])+7;
            int it=upper_bound(ages.begin(),ages.end(),search)-ages.begin();
            if(ages[i]>14){
            cnt+=(mp[ages[i]]-1);
            mp[ages[i]]--;
            if(mp[ages[i]]==0){
                mp.erase(ages[i]);
            }
            }
             if(it>i){
                continue;
            }
            else{
                cnt+=(i-it);
            }
        }
        return cnt;
    }
};