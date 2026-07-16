class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int>res(n,0);
        for(auto &x:shifts){
            int start=x[0];
            int end=x[1];
            int dir=x[2]; 
                res[start]+=(dir==1)?1:-1;
                if(end+1<n){
                    res[end+1]-=(dir==1)?1:(-1*1);
                }
        }
     int csum=0;
     for(int i=0;i<n;i++){
        csum+=res[i];
        res[i]=csum;
     }   
     //ab res[i]=net shift of ith element of the string,..
     for(int i=0;i<n;i++){
        int netshift=res[i]%26;
        s[i]='a'+(s[i]-'a'+netshift+26)%26;
     }
     return s;
    }
};