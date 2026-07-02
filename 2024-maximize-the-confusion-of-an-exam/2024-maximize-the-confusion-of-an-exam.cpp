class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l=0;
        int r=0;
       int t_count=0;
       int f_count=0;
       int maxlen=0;
       for(r=0;r<answerKey.size();r++){
        if(answerKey[r]=='T'){
            t_count++;
        }
        else{
            f_count++;
        }
        while(r-l+1-max(t_count,f_count)>k){//while invalid
            if(answerKey[l]=='F'){
                f_count--;
            }
            else{
                t_count--;
            }
            l++;
        }
        //now window is valid.
        maxlen=max(maxlen,r-l+1);
       }
       return maxlen;
        
    }
};