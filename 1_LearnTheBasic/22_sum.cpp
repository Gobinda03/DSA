#include<bits/stdc++.h>
using namespace std;
//parameterrised
void parameterised(int i,int sum){
if (i<1)
{
    cout<<sum;
    cout<<endl;
    return;
}
parameterised(i-1,sum+i);
}
//functional
int functional(int n){
    if (n==0)
    {//base case
        return 0;
    }
    else
    {
        return n+functional(n-1);
    }
    
    
}

//factorial
int factorial(int n){
    if (n==0)
    {//base case
        return 1;
    }
    else
    {
        return n*functional(n-1);
    }
    
    
}
int main()
{
int sum =0;
parameterised(6,0);
int n = 6;
cout << functional(n);
cout<< endl;
cout<<factorial(n);
return 0;
}