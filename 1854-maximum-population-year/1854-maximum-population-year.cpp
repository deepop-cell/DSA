class Solution {
public:
//Ye hai difference array technique.
    int maximumPopulation(vector<vector<int>>& logs) {
    vector<int>population(2051,0);
    for( auto &x:logs){
        int start=x[0];
        int end=x[1]-1;
        population[start]+=1;
        population[end+1]-=1;
    }    
    //now do csum.
    int maxpop_year=-1;
    int csum=0;
    int maxpop=INT_MIN;
    for(int i=0;i<=2050;i++){
        csum+=population[i];
        population[i]=csum;
        if(csum>maxpop){
            maxpop=csum;
            maxpop_year=i;
        }
    }
    return maxpop_year;
    }
};