class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        unordered_map<int,int>days;
        days[1]=0;
        days[2]=31;
        days[3]=59;
        days[4]=90;
        days[5]=120;
        days[6]=151;
        days[7]=181;
        days[8]=212;
        days[9]=243;
        days[10]=273;
        days[11]=304;
        days[12]=334;
     int aam=stoi(arriveAlice.substr(0,2));
     int gam=stoi(leaveAlice.substr(0,2));
     int abm=stoi(arriveBob.substr(0,2));
     int gbm=stoi(leaveBob.substr(0,2));
     int aad=stoi(arriveAlice.substr(3,2));
     int gad=stoi(leaveAlice.substr(3,2));
     int abd=stoi(arriveBob.substr(3,2));
     int gbd=stoi(leaveBob.substr(3,2));
     int Alice_AANA=days[aam]+aad;
     int Alice_JAANA=days[gam]+gad;
     int Bob_AANA=days[abm]+abd;
     int Bob_JAANA=days[gbm]+gbd;
     //when no meeting 
     if(Alice_JAANA<Bob_AANA ||Bob_JAANA<Alice_AANA){
        return 0;
     }
     return abs(max(Alice_AANA,Bob_AANA) - min(Alice_JAANA,Bob_JAANA))+1;
    }
};