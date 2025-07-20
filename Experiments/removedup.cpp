#include<bits/stdc++.h>
using namespace std;


void removedup(vector<int>&arr){

    int i = 0 ;
    int n = arr.size()-1;
    vector<int>result;
    int j = i+1;
    result.push_back(arr[0]);
    while(j!=n){
        
        if(arr[j]==arr[i]){
            j++;
        }
        else if(arr[j]>arr[i]){
            result.push_back(arr[i]);
            i=j;
            j++;
        }
    }

    for(int i = 0 ; i < result.size() ; i++){
        cout<< result[i]<<" ";
    }
}
int main()
{
    vector<int>arr= {0,0,0,1,1,2,2,2,3,3,4};
    removedup(arr);

    return 0;
}