#include<iostream>
using namespace std;
void printspiral(int arr[][10000],int n, int m){
int top=0;
int bottom=m-1;
int left=0;
int right=n-1;
while(top<=bottom && left<=right){
//top row
for(int j=left;j<=right;j++){
    cout<<arr[top][j];
}
top++;
//rightcolumn
for(int i=top;i<=bottom;i++){
    cout<<arr[i][right];
}
right--;
//bottom row
if(top<=bottom){
for(int j=right;j>=left;j--){
    cout<<arr[bottom][j];
}
}
bottom--;
//leftcolumn
if(left<=right){
for(int i=bottom;i>=top;i--){
    cout<<arr[i][left];
}
}
left++;
}
}