bool ithbit(int n, int i){
    int x=1<<i;
    return (n&x)!=0;
}