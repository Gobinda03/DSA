#include <bits/stdc++.h>
using namespace std;
int peakElement(vector<int>&arr, int n){
    if(n == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return n-1;

    int low = 1, high = n-2, mid;

    while(low<=high){
        mid = (high+low)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
        else if(arr[mid]>arr[mid-1]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int>arr = {1, 2, 3, 2, 3, 4, 5, 2, 1};
    int n = arr.size();
    for(auto it: arr){
        cout<<it<<" ";
    }
    
    cout<<"The index of the Peak element is: "<<peakElement(arr, n);
    return 0;
}