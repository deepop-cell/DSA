class Solution {
public:
    string digitSum(string s, int k) {
        string t=s;
        while(t.length()>k){
            string n="";
            int i=0;
            while(i<t.length()){
                int a=0;
                int j=i;
                for( j=i;j<min(i+k,(int)t.length());j++){
                a+=(t[j])-'0';
                }
                n+=to_string((a));
                i=j;
            }
            t=n;
        }
        return t;
    }
};