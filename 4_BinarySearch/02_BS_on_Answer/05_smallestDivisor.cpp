#include <bits/stdc++.h>
using namespace std;

int smallestDivisor(vector<int>&arr, int threshold){
    int low = 1, mid, high = *max_element(arr.begin(), arr.end()), sum;

    if(threshold < arr.size()) return -1;

    while(low <= high){
        mid = low + (high-low)/2;
        sum = 0;

        for(int i = 0; i < arr.size() ; i++){
            sum += ceil(double(arr[i])/double(mid));
        }

        if(sum <= threshold){
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
    cout<<"Enter the length of the array: ";
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i  = 0 ; i < n; i++){
        cin >> arr[i];
    }
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<"\nEnter the Threshold value: ";
    int threshold;
    cin>>threshold;

    cout<<"The smallest divisor is "<<smallestDivisor(arr,threshold)<<" where Threshold valye is "<<threshold;
    return 0;
}






// for linear search operation TC is Big O(max*N)
// For BS TC is Big O(log(max)*N)4