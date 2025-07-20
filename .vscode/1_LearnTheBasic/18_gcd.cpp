#include<bits/stdc++.h>
using namespace std;
//method 1
int gcd1(int a , int b)
{
    int gcd =1;
    for (int i = 1; i <= min(a,b); i++)
    {
        if (a%i==0&&b%i==0)
        {
            gcd=i;
        }
    }
    return gcd;
}

//method 2
int solve(int a , int b)
{
	// base case
	if(b==0) return  a;
	return solve(b,a%b);
}
int gcd(int a,int b)
{
	//Write your code here
	int ans = solve(max(a,b),min(a,b));
	return  ans;
}

int main()
{
    int n1, n2;
    cout<< "Enter the numbers "<<endl;
    cin>>n1>>n2;
    cout<<endl;
    cout<<"GCD is : ";
    cout << gcd(n1,n2);
    cout<<"GCD is : ";
    cout<< gcd1(n1,n2);
    cout<<endl;
return 0;
}