class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        //pehle dp ka table banao.
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        //state def : dp[i][j] ka matlab hai scss len of s1 of len i and s2 of len j.
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    //ek bhi empty string hui to dusri string ko poora hee lena padega
                    dp[i][j]=i+j;
                }
                else if(str1[i-1]==str2[j-1]){//equal hai to ek bar lo and move diagonally(yani dono mai aage badho)....
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    //unequal hai to min side jao kyuki min len ka scss chaiye....
                    dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);// ek char to loge hee kyuki ss bana rhe ho.
                }
            }
        }
        //now do reverse traversal from bottom right corner ....
        int i=n;
        int j=m;
        string res="";
        while(i>0 && j>0){
            //agar same hue 
            if(str1[i-1]==str2[j-1]){
                res.push_back(str1[i-1]);
                i--;
                j--;
                //move diagonally upwards.
            }
            else{
                //unequal hai to min side jana hai. ab jis side move kr rhe uska row ya col discard kr rhe ho to wo element ko push krlena/
                if(dp[i-1][j]<dp[i][j-1]){
                    res.push_back(str1[i-1]);//row poori uda rhe ho to us row ka char daldo .. row matlab s1/////
                    i--;//move upwards.
                }
                else{
                    res.push_back(str2[j-1]);//col poora uda rhe ho to us col ka char daldo ,,, col matalb s2......
                    j--;//move leftwards/
                }
            }
        }
        //iske baad leftover chars ko dalo.(if any)
        while(i>0){
            res.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            res.push_back(str2[j-1]);
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};