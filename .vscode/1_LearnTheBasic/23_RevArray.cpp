#include<bits/stdc++.h>
using namespace std;
void revarr(int f , int arr[],int l)
{
    if (f>=(l/2))
    {
        return;
    }
    else
    {
        // swap(arr[f],arr[l]);
        int temp = arr[f];
        arr[f]=arr[l-f];
        arr[l-f]=temp;

        revarr(f+1,arr,l);
    }
    
}
int main()
{
    int myarr[6];
    for (int i = 0; i < 6; i++)
    {
        cout<<"Your "<<i+1<<" element : ";
        cin>>myarr[i];
    }
    for (int i = 0; i < 6; i++)
    {
        cout<<myarr[i] <<" ";
    }
    cout<<endl;
    revarr(0,myarr,5);
    for (int i = 0; i < 6; i++)
    {
        cout<<myarr[i] <<" ";
    }
    
return 0;
}