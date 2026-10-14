class Solution {
public:
    int minFlips(int a, int b, int c) {
     // right most bit check kro .. 
     int flips=0;
     while(a>0 || b>>0 || c>0){
     int c_r=c&1;
     int a_r=a&1;
     int b_r=b&1;
     if(c_r==1){
        if(a_r !=1 && b_r!=1){
            flips++;
        }
     }  
     else{
        if(c_r==0){
            if(a_r!=0){
                flips++;
            }
            if(b_r!=0){
                flips++;
            }
        }
     }
     a>>=1;
     b>>=1;
     c>>=1; 
     }
     return flips;
    }
};