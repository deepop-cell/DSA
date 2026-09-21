class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length();
       int l=0;
       int r=0;
       long long cost=0;
       int maxlen=-1;
       for(r=0;r<n;r++){
       cost+=abs(s[r]-t[r]);
       while(cost>maxCost){
        cost-=abs(s[l]-t[l]);
        l++;
       }
       //now we have a valid window.
       maxlen=max(maxlen,r-l+1);
       } 
       return maxlen;
    }
};