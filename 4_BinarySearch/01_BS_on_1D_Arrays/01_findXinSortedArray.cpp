#include <bits/stdc++.h>
using namespace std;

// Iterative Method
int findK1(vector<int> &arr, int n, int t){
    int low = 0, high = n - 1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (arr[mid] == t){
            return mid;
        }
        else if (t > arr[mid]){
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return -1;
}



// recursive method
int search(vector<int>&arr, int low, int high, int k){
    if(low>high) return -1;

    int mid = (high + low) /2;
    if(arr[mid] == k) return mid;
    else if(arr[mid] > k) return search(arr, low, mid-1, k);
    else return search(arr, mid+1, high, k);
}
int foundTarget2(vector<int>&arr, int n, int k){
    if(arr.empty()) return 0;

    return search(arr, 0, n-1, k);
}


// TC = O(log2  N)


int main()
{
    vector<int>arr = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int n = arr.size();
    for(auto it: arr){
        cout<<it<<" ";
    }
    cout<<endl;

    cout<<target<<" found at index "<<findK1(arr, n, target)<<" using iterative method"<<endl;
    cout<<target<<" found at index "<<foundTarget2(arr, n, target)<<" using recursive method"<<endl;


    return 0;
}