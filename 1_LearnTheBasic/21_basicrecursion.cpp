#include <bits/stdc++.h>
using namespace std;
void name(int i, int n)
{
    if (i < n)
    {
        cout << "Gobinda" << " ";
    }
    else
    {
        return;
    }
    name(i + 1, n);
}
void revnum(int i, int n)
{
    if (i>=1)
    {
        cout<<i<<" ";
    }
    else
    {
        return;
    }
    revnum(i-1,n);
    
}
int main()
{
    name(1, 6);
    revnum(6,6);
    return 0;
}