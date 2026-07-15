class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i=0;
        while(1){
            if(s[i]==t[i]){
                i++;
            }
            else{
                return t[i];
            }
        }
        
    }
};