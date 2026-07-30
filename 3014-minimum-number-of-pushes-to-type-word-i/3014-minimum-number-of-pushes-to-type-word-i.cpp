class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        if(n<=8){
            return n;
        }
        int pushes=0;
        int k=n/8;
        int rem=n%8;
        pushes+=8*(k)*(k+1)/2;//sum of pushes for k groups of 8.
        pushes+=(rem)*(k+1);
        return pushes;
    }
};