#include <bits/stdc++.h>
using namespace std;


bool cowPlaced(vector<int>&arr, int dist, int cows){
    int countCows = 1, last = arr[0];

    for(int i = 0 ; i < arr.size() ; i++){
        if(arr[i]-last >= dist){
            countCows++;
            last = arr[i];
        }
    }
    if(countCows >= cows) return true;
    else return false;
}
int aggresiveCow(vector<int>&arr, int cows){
    sort(arr.begin(), arr.end());
    int low = 0, mid, high = arr[arr.size() - 1] - arr[0];

    while(low <= high){
        mid = low + (high-low)/2;

        if(cowPlaced(arr, mid, cows) == true){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
        
    }
    return high;
}

int main()
{
    cout<<"Enter the no of stalls: ";
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i  = 0 ; i < n; i++){
        cin >> arr[i];
    }
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<"\nEnter the value of cows, want to placed: ";
    int cows;
    cin>>cows;

    cout<<"The max of minimum distaance between cows: "<<aggresiveCow(arr,cows);
    return 0;
}




// for linear search operation TC is Big O(NlogN) + Big O((arr(Max) - arr(min)) * N)
// For BS TC is Big O(NlogN) + Big O((log(arr(Max) - arr(min))) * N)