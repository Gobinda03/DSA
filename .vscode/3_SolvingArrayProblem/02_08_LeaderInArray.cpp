#include<bits/stdc++.h>
using namespace std;
vector <int> leaderOfArray(vector<int>&ans){
    vector<int>arr;
    bool isLeader;
    int n = ans.size();
    for(int i=0 ; i<n ; i++){
        isLeader = true;
        for(int j = i+1 ; j<n ; j++){
            if(ans[j]>= ans[i]){
                isLeader = false;
                break;
            }
        }
        if(isLeader){
            arr.push_back(ans[i]);

        }
    }
    return arr;
}

vector<int> leader(vector<int>&arr){
    vector<int>ans;
    int n =arr.size();
    int maxi = arr[n-1];
    ans.push_back(arr[n-1]);
    for(int i= n-2 ; i>0 ; i-- ){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }

    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
    vector<int>arr;
    int n;
    cout<<"No of element : ";
    cin>>n;
    cout<<"Enter the element "<<"\n";
    for(int i = 0 ; i<n ; i++){
        int el;
        cin>>el;
        arr.push_back(el);
    }

    // for(int it : arr){
    //     cout<<it<<" ";
    // }

    cout<<"\n";

    // vector<int>ans = leaderOfArray(arr);
    vector<int>ans = leader(arr);
    for(int i = 0  ; i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}