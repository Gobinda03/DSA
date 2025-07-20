#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, count=0,ld;
    cout<<"enter the number: ";
    cin>>n;
    while (n!=0)
    {
        ld=n%10;
        n=n/10;
        count ++;

    }
    cout << "no of digits :"<<count;
    
return 0;
}