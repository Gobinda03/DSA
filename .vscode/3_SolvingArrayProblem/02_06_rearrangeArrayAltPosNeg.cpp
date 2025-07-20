#include <bits/stdc++.h>
using namespace std;
vector<int>rearrange1(vector<int>arr,int n)
{
    vector<int>pos;
    vector<int>neg;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>0)
        {
            pos.emplace_back(arr[i]);//{2,3,4,1}
        }
        else neg.emplace_back(arr[i]);//{-1,-3}
    }
    int size = min(pos.size(),neg.size());//2
    int maxi=max(pos.size(),neg.size());//4
    for (int i = 0; i < size; i++)
    {
        arr[2*i]=pos[i];
        arr[(2*i)+1] = neg[i];
    }
    int index = 2*size;
    for (int i = size; i < maxi ; i++)
    {
        if (pos.size()>size)
        {
            arr[index]=pos[i];
            index++;
        }
        else arr[index]=neg[i];
            index++;
        
    }
    
    return arr;
    
}
int main()
{
    ios::sync_with_stdio(false);
    int n=6;
    // cout << "Enter teh size of the array :";
    // cin >> n;
    vector<int> a={-1,2,3,4,-3,1};
    // int v = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>v;
    //     a.emplace_back(v);
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    vector<int>result=rearrange1(a,n);
    for (int i = 0; i < n; i++)
    {
        cout << result[i] <<" ";
    }
    return 0;
    }