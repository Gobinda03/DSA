#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,rn=0,ld,num;
    cout << "Enter the number : ";
    cin>> n;
    num =n;
    while (n>0||n<0)
    {
        ld =n%10;
        n=n/10;
        rn=(rn*10)+ld;
    }
    cout <<"Reverse of given no : "<< rn;
    
    if (num == rn)
    {
        cout<< "\nit is polindrone number";

    }
    else
   { cout<< "\nit is not a polindrone number";
   }    
    
return 0;
}