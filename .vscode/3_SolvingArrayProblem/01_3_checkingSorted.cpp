#include<bits/stdc++.h>
using namespace std;

bool checkSort(int arr[],int n)
{
    for (int i = 1; i < n; i++)
{
    if (arr[i]<arr[i-1])
    
        return false;
}
    
    
    return true;
    
    

}

bool sortingcheck(vector<int>&arr){
    int i = 0;
    int n = arr.size();
    int cnt=0;


    while(i!=n-1){
    if(arr[i]>arr[i+1]){
        i=i+1;
        break;
    }
    else if(arr[i]<=arr[i+1]){
        cnt++;
        i++;
    }
    }

    if(cnt==n) return 1;
    else 0;

    
}
int main()
{
vector<int>arr={3,4,5,1,2};
// int result = checkSort(arr,n);
cout<<sortingcheck(arr);
return 0;
}
