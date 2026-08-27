class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            vector<int>count(26,0);
            for(char ch:s)count[ch-'a']++;
            bool valid=true;
            for(int k=0;k<i;k++){
                if(--count[target[k]-'a']<0){
                    valid=false;
                    break;
                }
            }
            if(!valid)continue;
            for(int c=(target[i]-'a')+1;c<26;c++){
                if(count[c]>0){
                    string ans=target.substr(0,i);
                    ans+=(char)('a'+c);
                    count[c]--;
                    for(int rem=0;rem<26;rem++){
                        while(count[rem]-->0){
                            ans+=(char)('a'+rem);
                        }
                    }
                    return ans;
                }
            }
        }
        return "";
    }
};