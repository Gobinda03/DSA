#include <bits/stdc++.h>
using namespace std;

int noOfRotation(vector<int> &arr, int n){
    int high = n-1, low = 0, mid, ans = INT_MAX;
    int index = -1;
    while(low <= high){
        mid = (low+high)/2;

        if(arr[low] <= arr[high]){
            if(arr[low]<ans){
                index = low;
                ans = arr[low];
                break;
            }
        }

        if(arr[low] <= arr[mid]){
            if(arr[low]<ans){
                index = low; 
                ans = arr[low];     
            }
            low = mid+1;
        }
        else{
            if(arr[mid]<=ans){
                index = mid;
                ans = arr[mid];   
            }
            high = mid-1;
        }
    }
    return index;
}
int main()
{
    vector<int>arr={3, 4, 5, 1, 2};
    int n = arr.size();
    for(auto it : arr){
        cout<< it<<" ";
    }

    int ans = noOfRotation(arr, n);
    cout<<"\nArray was rotated "<<ans<<" times.";
    return 0;
}