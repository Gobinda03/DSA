#include<bits/stdc++.h>
using namespace std;

int main()
{
int a,b;
cin>> a>>b;
cout<<endl;
while (a>0&&b>0)
{
    if (a>b)
    {
        a=a%b;
    }
    else
    {
        b=b%a;
    }  
}
if (a==0)
{
    cout<<b;
}
else
{
    cout<<a;
}



return 0;
}