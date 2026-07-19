class Solution {
public:
int solve(int i){
    if(i<=1){
        return 1;
    }
    int ans=0;
    for(int k=1;k<=i;k++){
        int leftpossible=solve(k-1);// k par khade ho to  usko fix kroge to left mai k-1 bache
        //1,2,3,4,5,6,7,,,,i . if i am at 7 making it root then 1 to 6 can be chosen for leftsubtree and 8 to i for right subtree. mutply total ways to get the ans
        int rightpossible=solve(i-k);
        ans+=leftpossible*rightpossible;
    }
    return ans;//this is the ans if there were i nodes.
}
    int numTrees(int n) {
        //this is a dp problem. see if we are at any i, we can choose numbers from 1 to i-1 to form leftsubtree and for right subtree we can chose from i+1 to n.. and total possible will be totalleftways*totalrightways..

    return solve(n);
        
    }
};