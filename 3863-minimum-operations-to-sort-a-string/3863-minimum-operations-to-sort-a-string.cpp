class Solution {
public:
bool sorted(string &s){
    for(int i=0;i<s.length()-1;i++){
        if(s[i+1]<s[i]){
            return false;
        }
    }
    return true;
}
    int minOperations(string s) {
        int n=s.length();
        if(n==2){
            //and aagr isme sorted nahi hai to impossible hai 
        if(!sorted(s)){
            return -1;
        }
        else{
            return 0;
        }
        }
        if(sorted(s)){
            return 0;
        }
        int mn=-1;
        int mx=-1;
        char mxch='a';
        char mnch='z';
        bool mnatf=false;
        int mncnt=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
        if(ch>=mxch){
         mxch=ch;
         mx=i;
        }
        if(ch<=mnch){
            mnch=ch;
            mn=i;
        }
        }
        if(s[0]==mnch){
            mnatf=true;
        }
        for(auto &ch:s){
            if(ch==mnch){
                mncnt++;
            }
        }
        if(mx==n-1 || mn == 0){
            //ek to apni jagah pe fix hai 
            return 1;
        }
        else if(mx==0 && mn== n-1 && mncnt==1){
            //2 lag jaynge usko correct mai le jane ke aur baki ke liye +1
            return 3;
        }
        else if(mnatf){
          return 1;  
        }
        else{
            return 2;
        }
    }
};