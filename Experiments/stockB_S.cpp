#include<bits/stdc++.h>
using namespace std;


// int Stock(vector<int>arr){

//     int i =0 , j = i+1 ;
//     int totalprofit=0;
//     int maxprofit=0;

//     while(j<=arr.size()){
//         if(arr[j]>arr[i] && arr[j]>arr[j-1]){
//             int profit = arr[j]- arr[i];
//             maxprofit = max(maxprofit,profit);
//             j++;
//         }


//         else{
//             i=j;
//             j++;
//             maxprofit=0;
            
//             totalprofit += maxprofit;
//         }
//     }

//     return totalprofit;

// }

int stock(vector<int>&price){
    int buy = 0 , sell = 1, profit = 0 , maxprofit = 0 ;
    int n = price.size();

    while(sell!=n){
        
        if(price[buy]<price[sell]){
            int p = price[sell]-price[buy];
            profit=max(profit,p);
            maxprofit=max(maxprofit,profit);
        }

        else{
            buy = sell;
        }

        sell++;
    }

    return maxprofit;
}

int main(){
    vector<int>a = {1,9,12};
    int result = stock(a);
    cout<<result;
    return 0;
}