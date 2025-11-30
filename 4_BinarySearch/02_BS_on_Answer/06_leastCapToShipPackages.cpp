#include <bits/stdc++.h>
using namespace std;

int leastCaoToShip(vector<int>&weight, int givenDays){

    int low = *max_element(weight.begin(), weight.end()), mid, high = accumulate(weight.begin(), weight.end(), 0);

    while(low <= high){
        mid = low + (high-low)/2;

        int days = 1, load = 0;
        for(int i = 0; i < weight.size() ; i++){
            if(load + weight[i] > mid){
                days +=1;
                load = weight[i];
            }
            else{
                load += weight[i];
            }
        }

        if(days <= givenDays){
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
    cout<<"Enter the no of packages: ";
    int n;
    cin>>n;

    vector<int>weight(n);
    for(int i  = 0 ; i < n; i++){
        cin >> weight[i];
    }
    for(auto it : weight){
        cout<<it<<" ";
    }
    cout<<"\nEnter the no of day you want to deliver all the packages: ";
    int givenDay;
    cin>>givenDay;

    cout<<"The least capacity is "<<leastCaoToShip(weight,givenDay)<<" for which all the packages will be shipped within "<<givenDay<<" days.";
    return 0;
}




// for linear search operation TC is Big O(sum-max+1) * Big O(N)
// For BS TC is Big O(log(sum-max)+1) * Big O(N)