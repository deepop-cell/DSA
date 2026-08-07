class Solution {
public:
typedef long long ll;
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n=tasks.size();
        vector<ll>prefix(n);
        ll cs=0;
        for(int i=0;i<n;i++){
            cs+=tasks[i];
            prefix[i]=cs;
        }
        vector<int>ans(shifts.size());
        int idx=0;
        ll c=0;
        for(int i=0;i<shifts.size();i++){
            c+=shifts[i];
        idx=upper_bound(prefix.begin(),prefix.end(),c)-prefix.begin();
        if(idx==n){
            ans[i]=0;
            idx=0;
            c=0;
        }
        else{
            ans[i]=n-idx;
        }
        }
        return ans;
    }
};