#include<bits/stdc++.h>
using namespace std;

int main()
{
int array[5]={5,6,8,6,4};
// for (int i = 0; i < 5; i++)
// {
//     cout<<array[i]<<" ";
// }
// for (int i = 0; i < 5; i++)
// {
//     int temp=array[i];
//     array[i]=array[i+1];
//     array[i+1]=temp;
// }
// cout<<endl;
// for (int i = 0; i < 5; i++)
// {
//     cout<<array[i]<<" ";
// }
int n=5;
int low = 0, high = n-1;
    for(int i = 0; i<n ; i++)
    {
        while(low!=high)
        {
            swap(array[low],array[high]);
            low++;
            high--;
        }
    }
    for(int i =0 ; i<n ; i++)
    {
        cout<<array[i];
    }

return 0;
}