class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        //range based updating ki baat ho rahi hai.. therefore difference array technique use krenge.
        int n=s.length();
        vector<int>res(n,0);
        for(auto &x : shifts){
            int start=x[0];
            int end=x[1];
            int dir=x[2];
            if(dir==1){
                //matlab ahead...
                res[start]+=1;
                if(end+1<n){
                    res[end+1]-=1;
                }
            }
            else{
                res[start]-=1;
                if(end+1<n){
                    res[end+1]+=1;
                }
            }
        }
        //now do csum thing on res..
        int csum=0;
        for(int i=0;i<n;i++){
            csum+=res[i];
            res[i]=csum;
        }
        //ab res[i] is denoting the net shift in ith index of the string..
        for(int i=0;i<n;i++){
            int shift=res[i];
            shift=shift%26;
            if(shift<0){
                shift+=26;
            }
            s[i]='a'+(s[i]-'a'+shift)%26;
        }
        return s;
    }
};