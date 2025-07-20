#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10]={1,0,1,1,0,1,1,1,1,0};
    int maxi =0,cnt=0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i]==1)
        {
            cnt +=1;
            maxi=max(maxi,cnt);
        }
        else
        {
            cnt = 0;
        }  
    }
    cout<<maxi;
    
return 0;
}