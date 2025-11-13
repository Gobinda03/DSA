#include <bits/stdc++.h>
using namespace std;

int possibility(vector<int> &arr, int n, int m){
    if((long long)arr.size()< (long long)n*m) return -1;


    int low = 1, high = *max_element(arr.begin(), arr.end()), mid, count;
    int result = -1;
    while(low <= high){
        mid = low + (high-low)/2;
        int cnt = 0, bouquets = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i]<=mid){
                cnt++;
            }
            else{
                bouquets += cnt/m;
                cnt = 0;
            }
        }
        bouquets += cnt/m;

        if(bouquets<n){
            low = mid+1;
        }
        else{
            result = mid;
            high = mid -1;
        }    
    }

    return result;
}


int main()
{
    vector<int>arr = {7, 7, 7, 7,  11, 12, 7, 8, 9, 14, 18};
    for(auto it: arr){
        cout<<it<<" ";
    }
    int n, m;
    cout<<"\nNo of bouquets need: ";
    cin>>n;
    cout<<"\nNo of consecutive day: ";
    cin>>m;

    cout<<"minimum bloom day: "<<possibility(arr, n, m);
    return 0;
}