// int count_min_days(int arr[], int n, int m, int k){
//     if(k*m > n) return -1;

//     int low = min(arr,n);
//     int high = max(arr,n);

//     for(int day = low; day <= high; day++){
//         int count = 0, bouquets = 0;

//         for(int i = 0; i < n; i++){
//             if(arr[i] <= day){
//                 count++;
//                 if(count == k){
//                     bouquets++;
//                     count = 0;
//                 }
//             } else {
//                 count = 0;
//             }
//         }

//         if(bouquets >= m){
//             return day;
//         }
//     }
//     return -1;
//}
//this is brute force , but its O(n2). we do binary instead
//binary approach
bool canmake(int arr[],int n,int m,int k,int day){
    int count=0;
    int bouqets=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=day){
            count++;
            if(count==k){
                bouqets++;
                count=0;
            }
        }
        else{
            count=0;
        }
    }
    return bouqets>=m ;
}
int day(int arr[], int n,int m,int k){
    if(k*m>n){
        return -1;
    }
    int low=arr[0];
    int high=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<low){
            low=arr[i];
        }
        if(arr[i]>high){
            high=arr[i];
        }
    }
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(canmake(arr,n,m,k,mid)){
            high=mid-1;
            ans=mid;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}