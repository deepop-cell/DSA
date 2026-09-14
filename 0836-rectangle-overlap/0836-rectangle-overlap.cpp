class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
       ///we can take projection .
       //for rec 1.
       int A=rec1[0];
       int B=rec1[2];
       int C=rec2[0];
       int D=rec2[2];
       int a=rec1[1];
       int b=rec1[3];
       int c=rec2[1];
       int d=rec2[3];
       bool Z=false;
       bool UFFF=false;
       if(max(A,C)<min(B,D)){
        Z=true;;
       }
       if(max(a,c)<min(b,d)){
        UFFF=true;
       }
       return Z&&UFFF;
    }
};