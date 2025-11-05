#include <bits/stdc++.h>
using namespace std;

int minInRotatedArr(vector<int>&arr, int n){
    int low = 0, high= n-1, ans = INT_MAX, mid;

    while(low<=high){
        mid = (high+low)/2;

        if(arr[low]<=arr[mid]){
            ans = min(ans, arr[low]);
            low = mid +1;
        }
        else{
            ans = min(ans, arr[mid]);
            high = mid-1;
        }
    }
    return ans;

}
int main()
{
    vector<int>arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = arr.size();
    for(auto it: arr){
        cout<<it<<" ";
    }
    cout<<endl;

    int ans = minInRotatedArr(arr, n);
    cout<<"Minimun: "<<ans;
    return 0;
}