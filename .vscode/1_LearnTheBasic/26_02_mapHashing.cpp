#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<< "Enter the number of array :";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    //precompute 
    map<int ,int>mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]+=1;
    }
    int q;
    // cin>>q;
    while (n--)
    {
        int number;
        cout<<"enter the number u want to know the apperance : ";
        cin>> number;
        //fatching
        cout<<mpp[number];
        cout<<endl;
    }
    
    
return 0;
}