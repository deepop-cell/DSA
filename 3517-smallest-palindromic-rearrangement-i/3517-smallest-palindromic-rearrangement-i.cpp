class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        if(n==1){
            return s;
        }
        string ans="";
        if(n%2==0){
            //even len
            string temp="";
            for(int i=0;i<(n/2);i++){
                temp+=s[i];
            }
            sort(temp.begin(),temp.end());
            string y=temp;
            reverse(y.begin(),y.end());
            ans+=temp;
            ans+=y;
        }
        else{
            //odd len
            char mid=s[n/2];
            string temp="";
            for(int i=0;i<(n/2);i++){
                temp+=s[i];
            }
            sort(temp.begin(),temp.end());
            string y=temp;
            reverse(y.begin(),y.end());
            ans+=temp;
            ans+=mid;
            ans+=y;
        }
        return ans;
        
    }
};