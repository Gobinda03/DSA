#include <bits/stdc++.h>
using namespace std;

//maximum of the array
int maximum(vector<int>&arr){
    int n = arr.size();
    int maxi = INT_MIN;
    for(int i = 0; i<n ; i++){
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

//total time taken to eat all bananas
long long totalHrs(vector<int>&arr, int hourly){
        long long hours = 0;
        for(int bananas : arr){
            hours += (bananas+hourly-1)/hourly;
        }
        return hours;
}

int eatsBananas(vector<int> &arr, int hrs){
    int low = 1, high = maximum(arr), mid;
    int ans = 0;
    while(low<= high){
        mid = (low + high)/2;

        long long totalTime = totalHrs(arr, mid);

        if(totalTime <= hrs){
            ans = mid;
            high = mid-1; 
        }
        else{
            low = mid+1;
        }
    }
    return low;
}




int main()
{
    vector<int>piles = {805306368,805306368,805306368};
    int h = 1000000000;
    for(auto it : piles){
        cout<<it<<" ";
    }
    cout<<"koko will eat "<<eatsBananas(piles, h)<< " bananas per hour";
    return 0;
}