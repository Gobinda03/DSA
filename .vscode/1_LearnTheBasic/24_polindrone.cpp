#include<bits/stdc++.h>
using namespace std;
bool f(int i,string &a)
{
    if (i>=a.size()/2)
    {
        return true;
    }
    if (a[i]!=a[a.size()-i-1])
    {
        return false;
    }
    
        return f(i+1,a);
}
int main()
{
string s="abcba";
cout<<f(0,s);
return 0;
}