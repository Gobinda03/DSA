/*#include<bits/stdc++.h>
using namespace std;
int slarge(int n , vector<int> &a)
{
    int large =a[0];
    int secondlarge = -1;
    for(int i =0 ; i<n ; i++)
    {
        if(a[i]>large)
        {
            secondlarge=large;
            large = a[i];
        }
        else if (a[i]<large&&a[i]>secondlarge)
        {
            secondlarge=a[i];
        }
    }
    return secondlarge;
}
int ssmall(int n , vector<int> &a)
{
    int small =a[0];
    int secondsmall = 10e5;
    for(int i =0 ; i<n ; i++)
    {
        if(a[i]<small)
        {
            secondsmall=small;
            small = a[i];
        }
        else if (a[i]>small&&a[i]<secondsmall)
        {
            secondsmall=a[i];
        }
    }
    return secondsmall;
}
vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.
    int secondlargest = slarge(n,a);
    int seconsmallest = ssmall(n,a);
    vector<int> result;
    result.push_back(secondlargest);
    result.push_back(seconsmallest);
    return result;
}
*/
#include <bits/stdc++.h>
using namespace std;

int getElements(int array[], int n)
{
    if (n == 0 || n == 1)
    {
        cout << -1 << " " << -1 << endl;
    }
    int small = INT_MAX, secondSmall = INT_MAX;
    int large = INT_MIN, secondLarge = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        small = min(small, array[i]);
        large = max(large, array[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (array[i] > secondLarge && array[i] != large)
    
        secondLarge = array[i];

        if (array[i] < secondSmall && array[i] != small)

        secondSmall = array[i];
    }
    cout << "\nthe largest element : " << large;
    cout << "\nthe smallest element : " << small;
    cout << "\nthe Second_largest element : " << secondLarge;
    cout << "\nthe Second_smallest element : " << secondSmall;
}

 int getSecondLargest(vector<int> &arr) {
        // Code Here
        int large = -1 , slarge = -1;
        int n = arr.size();
        if(n==0 || n==1) return -1;
        
        for( int i = 0 ; i <= n ; i++){
            
            if(arr[i]>=large){
                large = arr[i];
            }
        }
        
        for(int j = 0 ; j < n ; j++){
            if(arr[j]>slarge && arr[j] <  large){
                slarge = arr[j];
            }
        }
        return slarge;
        
        return (slarge==-1) ? -1 : slarge ;
        
    }



    vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.
    int large , slarge , small , ssmall;
    vector<int>v;
    small =  INT_MAX;
    ssmall = INT_MAX;
    large = INT_MIN;
    slarge = INT_MIN;

    for(int i = 0 ; i<n ; i++){
        if(a[i]>large) {
            large = a[i];
        }
        if(a[i]<small){
            small=a[i];
        }
    }

    for(int j= 0 ; j<n ; j++){
        if(a[j]>slarge && slarge < large){
            slarge=a[j];
            }
        
        if(a[j]<ssmall && ssmall > small){
            ssmall=a[j]; 
            }
    }
        v.push_back(slarge);
        v.push_back(ssmall);
        return v;
}

int main()
{
   vector<int> arr = {22781,3129,27080,16834,9359,17899,9920,3833,27089,17326};
    int n = sizeof(arr) / sizeof(arr[0]);
    // getElements(arr, n);
    cout<<getSecondLargest(arr);
    getSecondOrderElements(n,arr);

    // cout<< sizeof(arr);
    return 0;
}