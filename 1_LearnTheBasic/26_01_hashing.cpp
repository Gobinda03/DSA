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
    int hash[13]={0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]+=1;
    }
    int q;
    cin>>q;
    while (q--)
    {
        int number;
        cout<<"enter the number u want to know the apperance : ";
        cin>> number;
        //fatching
        cout<<hash[number];
        cout<<endl;
    }
    
    
return 0;
}