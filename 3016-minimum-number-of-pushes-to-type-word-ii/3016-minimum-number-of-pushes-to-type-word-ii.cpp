class Solution {
public:
    int minimumPushes(string word) {
    vector<int>freq(26,0);
    for(int i=0;i<word.length();i++){
        freq[word[i]-'a']++;
    }
    sort(freq.begin(),freq.end());
    reverse(freq.begin(),freq.end());
    int x=26;
    for(int i=0;i<26;i++){
        if(freq[i]==0){
            x=i;
            break;
        }
    }
    vector<int>freq2(x,0);
    for(int i=0;i<x;i++){
        freq2[i]=freq[i];
    }
    int pushes=0;
    int take=0;
    int coeff=1;
    for(int i=0;i<x;i++){
        if(take==8){
            coeff++;
            take=0;
        }
        pushes+=(coeff)*(freq2[i]);
        take++;
    }
    return pushes;
    }
};