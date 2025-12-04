#include <bits/stdc++.h>
using namespace std;

int countPart(vector<int>&arr, int mid){
    int countPart = 1, count = 0;

    for(int i = 0 ; i < arr.size() ; i++){
        if(count + arr[i] <= mid){
            count += arr[i];
        }
        else{
            countPart++;
            count = arr[i];
        }
    }
    return countPart;
}

int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end()), mid, high = accumulate(nums.begin(), nums.end(),0);

    while(low <= high){
        mid = low + (high-low)/2;
        int countpartition = countPart(nums, mid);
        if(countpartition > k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
        
    }
    return low;
}


int main()
{
    cout<<"Enter the no of elements: ";
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i  = 0 ; i < n; i++){
        cin >> arr[i];
    }
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<"\nEnter the number of partition: ";
    int students;
    cin>>students;

    cout<<"The minmun of all maximum partition: "<<splitArray(arr,students);
    return 0;
}




// for linear search operation TC is Big O(sum - max + 1)*N
// For BS TC is Big O((log(sum - max+1)) * N)