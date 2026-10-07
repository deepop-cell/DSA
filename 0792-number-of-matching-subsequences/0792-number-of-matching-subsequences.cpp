class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>>mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            mp[s[i]].push_back(i);
        }
        int cnt=0;
        for(int k=0;k<words.size();k++){
            string curr=words[k];
            int prev=-1;
            int j=0;
            for( j=0;j<words[k].size();j++){
                auto &it=mp[curr[j]];
                auto idx=upper_bound(it.begin(),it.end(),prev);
                if(idx==it.end()){
                break;
                }
                prev=*idx;
            }
            if(j==words[k].size()){
                cnt++;
            }
        }
        return cnt;

    }
};