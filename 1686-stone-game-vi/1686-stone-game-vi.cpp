class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n=aliceValues.size();
        vector<pair<int,int>>stones(n);
        //we will store total sum , alice avlues in this,
        int alicescore=0;
        int bobscore=0;
        for(int i=0;i<n;i++){
            stones[i]={aliceValues[i]+bobValues[i],aliceValues[i]};
        }
        //now sorrt it and in pair sorting happens acooridnig to the first.
        sort(stones.rbegin(),stones.rend());
        for(int i=0;i<n;i++){
            int sum=stones[i].first;
            int a=stones[i].second;
            if(i%2==0){
                //alice ki turn hai.
                alicescore+=a;
            }
            else{
                //bob ki turn hai.
                bobscore+=sum-a;
            }
        }
        if(alicescore>bobscore){
            return 1;
        }
        else if(alicescore<bobscore){
            return -1;
        }
        else{
            return 0;
        }
    }
};