class Solution {
public:
    int reverseDegree(string s) {
    int z=26;
    vector<int>revdeg(26);
    for(int i=0;i<26;i++){
        revdeg[i]=z;
        z--;
    }
    long long sum=0;
    for(int i=0;i<s.length();i++){
        sum+=(revdeg[s[i]-'a']*(i+1));
    }
    return sum;
    }
};