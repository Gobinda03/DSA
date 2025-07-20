#include<bits/stdc++.h>
using namespace std;
// better 
vector<int>movezero(int n, vector<int>a)
{
    //step 1
    vector<int>temp;
    for (int i = 0; i < n; i++)
    {
        if (a[i]!=0)
        {
            temp.push_back(a[i]);
        }
    }
    //step 2
    int nz=temp.size();
    for (int i = 0; i < nz; i++)
    {
        a[i]=temp[i];
    }
    //step 3
    for (int i = nz; i < n; i++)
    {
        a[i]=0;
    }
    return a;
}
//optimal
vector<int>moveZero(int n,vector<int>a)
{
    int j=-1;
    for (int i = 0; i < n; i++)
    {
        if (a[i]==0)
        {
            j=i;
            break;
        }
    }
        if (j==-1)
        {
            return a;
        }
        for (int i = j+1; i < n; i++)
        {
            if (a[i]!=0)
            {
                swap(a[i],a[j]);
                j++;
            }
        }
    return a; 
}
int main()
{
    vector<int>array={1,0,2,3,0,4,5,0,6,7};
    int n=10;
    vector<int>ans=movezero(n,array);
    for (auto &it : ans)
    {
        cout<<it <<" ";
    }
    cout<<endl;
    vector<int>Ans=moveZero(n,array);
    for (auto &it : Ans)
    {
        cout<<it <<" ";
    }
    cout<<'\n';
    return 0;
}