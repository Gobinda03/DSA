#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,rn=0,ld;
    cout << "Enter the number : ";
    cin>> n;
    while (n>0||n<0)
    {
        ld =n%10;
        n=n/10;
        rn=(rn*10)+ld;
    }
    cout <<"Reverse of given no : "<< rn;
    
return 0;
}