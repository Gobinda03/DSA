#include<bits/stdc++.h>
using namespace std;
int linearsearch(int arr[],int n,int s)
{
for (int i = 0; i < n; i++)
    {
        if (arr[i]==s)
        {
            return i;
        }
    }
    return -1;
    }
int main()
{
    int n,s;
    cout<<"Enter the no of array :";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"Enter the no u want to search :";
    cin>>s;
    cout<<"Result :"<<linearsearch(arr,n,s);
return 0;
}