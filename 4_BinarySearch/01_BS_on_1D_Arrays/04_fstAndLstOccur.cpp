#include <bits/stdc++.h>
using namespace std;

// First occur
int firstOccur(vector<int> &arr, int n, int target){
    int low = 0, high = n-1;
    int ans = -1;

    while(low<=high){
        int mid = (low+high)/2;
        
        if(arr[mid] == target){
            ans = mid;
            high = mid -1;
        }
        else if(target>arr[mid]){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return ans;
}

// last Occur
int lastOccur(vector<int>&arr, int n, int target){
        int low = 0, high = n-1;
        int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        
        if(arr[mid] == target){
            ans = mid;
            low = mid + 1;
        }
        else if(target>arr[mid]){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return ans;
}


pair<int, int> firstAndLast(vector<int>&arr, int n, int k){
    int first = firstOccur(arr,n,k);
    if(first == -1) return{-1, -1};
    int last = lastOccur(arr, n, k);
    return {first, last};
}

int firstAndLastCount(vector<int>&arr, int n, int k){
    int first = firstOccur(arr,n,k);
    if(first == -1) return -1;
    int last = lastOccur(arr, n, k);
    return {last - first +1};
}





// TC = O(2log2  N)


int main()
{
    vector<int>arr = {3, 4, 6, 7, 7, 7, 9, 12,  16, 17};
    int target = 7;
    int n = arr.size();
    for(auto it: arr){
        cout<<it<<" ";
    }
    cout<<endl;
    // auto lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    // cout<<lb;


    cout<<target<<" occur for first time at index "<<firstOccur(arr, n, target)<<endl;
    cout<<target<<" occur for last time at index "<<lastOccur(arr, n, target)<<endl;
    cout<<"Difference between first and last occurrence is: "<<firstAndLastCount(arr,n,target)<<endl;


    return 0;
}