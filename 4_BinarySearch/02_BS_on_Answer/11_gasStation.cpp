#include <bits/stdc++.h>
using namespace std;

long double gasStationSetup(vector<int> &arr, int k){
    vector<int>howMany(arr.size()-1, 0);
    priority_queue<pair<long double , int>>pq;
    for(int i = 0 ; i < arr.size()-1 ; i++){
        pq.push({arr[i+1]-arr[i], i});
    }

    for(int station = 1 ; station <= k ; station++){
        auto top = pq.top();
        pq.pop();

        int section_ind = top.second;
        howMany[section_ind]++;
        long double diff = (long double)arr[section_ind+1] - arr[section_ind];
        long double section_len = diff/((long double)howMany[section_ind]+1);
        pq.push({section_len, section_ind});
    }

    return pq.top().first;
}

int main()
{
    cout<<"Enter the no of location: ";
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i  = 0 ; i < n; i++){
        cin >> arr[i];
    }
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<"\nEnter the number of Gas Station want to set up: ";
    int gs;
    cin>>gs;

    cout<<"The minimized of maximun distance bwtween two gas Station is: "<<gasStationSetup(arr,gs);
    return 0;
}
