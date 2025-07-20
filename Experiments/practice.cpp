#include<bits/stdc++.h>
using namespace std;

int FindEle(vector<int>&arr,int target){

    int n = arr.size();
    vector<int>temp;
    for (int i = 0; i <n ; i++){
        for(int j = i+1 ; j<n ; j++){
            if(arr[i]+arr[j]==target){
                cout<<i<<","<<j<<"\n";
                return 1;
            }

        }
    }
    return -1;

    
}

int searchEle(vector<int>&array , int target){
    int n = array.size();
    map<int , int > mpp;
    for(int i = 0 ; i<n ; i++){
        int a = array[i];
        int more = target - a;
        if(mpp.find(more) != mpp.end()){
            return 1;
        }
        mpp[a]=i;
    }
    return -1;
}


int main()
{
    vector<int>arr;

    int n = 5;
    for(int i = 0 ; i<n ; i++){
        int num;
        cin>> num;
        arr.push_back(num);
    }
    
    for(auto val : arr){
        cout<<val<<" ";

    }
    cout<<"\n";
    int target = 7;
    cout<<FindEle(arr,target);
    cout<<searchEle(arr,target);
    return 0;
}