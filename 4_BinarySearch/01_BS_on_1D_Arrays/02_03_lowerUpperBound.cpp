#include <bits/stdc++.h>
using namespace std;

// Lower Bound
int lower(vector<int> &arr, int n, int target){
    int low = 0, high = n-1;
    int ans = n;

    while(low<=high){
        int mid = (low+high)/2;
        
        if(arr[mid] >= target){
            ans = mid;
            high = mid -1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}




int upper(vector<int>&arr, int n, int target){
        int low = 0, high = n-1;
        int ans = n;

    while(low<=high){
        int mid = (low+high)/2;
        
        if(arr[mid] > target){
            ans = mid;
            high = mid -1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}


// TC = O(log2  N)


int main()
{
    vector<int>arr = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 7;
    int n = arr.size();
    for(auto it: arr){
        cout<<it<<" ";
    }
    cout<<endl;
    // auto lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    // cout<<lb;


    cout<<target<<"'s lower bound found at index "<<lower(arr, n, target)<<" using iterative method"<<endl;
    cout<<target<<"'s upper bound found at index "<<upper(arr, n, target)<<" using iterative method"<<endl;


    return 0;
}