class Solution {
public:
typedef long long ll;
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=shifts.size();
        vector<ll>res(n,0);
        for(int i=0;i<n;i++){
            int start=0;
            int end=i+1;
            ll sum=shifts[i];
            res[start]+=sum;
            if(end<n){
                res[end]-=sum;
            }
        }
        ll csum=0;
        for(int i=0;i<n;i++){
            csum+=res[i];
            res[i]=csum;
        }
        for(int i=0;i<n;i++){
            s[i]='a'+(s[i]-'a'+res[i])%26;
        }
        return s;
        
    }
};