#include <bits/stdc++.h>
using namespace std;

int kthMissingNo(vector<int>&arr, int k){

    int low = 0, mid, high = arr.size()-1;

    while(low <= high){
        mid = low + (high-low)/2;
        int missing = arr[mid] - (mid+1);

        if(missing < k){
            low = mid +1;
        }
        else{
            high = mid -1;
        }
    }
    return low + k;
}

int main()
{
    cout<<"Enter the no Element: ";
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i  = 0 ; i < n; i++){
        cin >> arr[i];
    }
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<"\nEnter the position of the number u want to find out: ";
    int K;
    cin>>K;

    cout<<"The Kth missing ter is: "<<kthMissingNo(arr,K);
    return 0;
}




// for linear search operation TC is Big O(N)
// For BS TC is Big O(logN)