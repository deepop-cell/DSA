class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l=0;
        int c_1=0;
        int r=0;
        int minlen=INT_MAX;
        vector<string>ans;
        for(int r=0;r<s.length();r++){
            if(s[r]=='1'){
                c_1++;
            }
            while(c_1==k){
                while(s[l]=='0'){
                    l++;
                }
                int currlen=r-l+1;
                if(minlen>currlen){
                    ans.clear();
                    minlen=currlen;
                    ans.push_back(s.substr(l,r-l+1));
                }
                else if(currlen==minlen){
                    ans.push_back(s.substr(l,r-l+1));
                }
                l++;
                c_1--;
            }
        }
        sort(ans.begin(),ans.end());
        return (ans.empty())?"":ans[0];
    }
};