
#include<iostream>
#include<cstring>
int main(){
int n;
std::cin>>n;
std::cin.ignore();
std::string str[n];
for(int i=0;i<n;i++){
    getline(std::cin,str[i]);
}

std::string temp="";

for(int i=0;i<str[0].size();i++){
    char ch=str[0][i];
    bool ok=true;
    for(int j=1;j<n;j++){
        if(i>=str[j].length() || str[j][i]!=ch){
            ok=false;
            break;
        }
    }
        if(!ok){
            break;
        }
    temp+=ch;
}
        











    return 0;
}