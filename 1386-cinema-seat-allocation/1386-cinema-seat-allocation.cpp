class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int count=0;
        unordered_map<int,vector<int>>mp;
        for(auto &seat:reservedSeats){
            mp[seat[0]].push_back(seat[1]);
            //row---.reserved seat
        }
        count+=(n-mp.size())*2;
        for(auto &it:mp){
            vector<bool>res(11,false);
            for(auto &seat:it.second){
                res[seat]=true;
            }
            bool x=false;
            bool x1=false;
            for(int j=2;j<=5;j++){
                if(res[j]){
                    x=true;
                    break;
                }
            }
            if(!x){
                 x1=true;//seat de rha hu
                count++;
            }
            bool y=false;
            bool y1=false;
            for(int j=4;j<=7;j++){
                if(res[j]){
                    y=true;
                    break;
                }
            }
            if(!y && !x1){
                y1=true;//seat de rha hu
                count++;
            }
            bool z=false;
            for(int j=6;j<=9;j++){
                if(res[j]){
                    z=true;
                    break;
                }
            }
            if(!z && !y1){
                count++;
            }
        }
        return count;
    }
};