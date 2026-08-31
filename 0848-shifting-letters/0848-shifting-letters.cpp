class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.length();
        vector<long long>diff(n,0);
        for(int i=0;i<shifts.size();i++){
            int start=0;
            int end=i;
            int val=shifts[i];
            diff[start]+=val;
            if(end+1<n){
                diff[end+1]-=val;
            }
        }
        long long csum=0;
        for(int i=0;i<n;i++){
            csum+=diff[i];
            diff[i]=csum;
        }
        ///now diff i means net shift in the ith character.
        for(int i=0;i<n;i++){
            s[i]='a'+(s[i]-'a'+(diff[i]%26))%26;
        }
        return s;
    }
};