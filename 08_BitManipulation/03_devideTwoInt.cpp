#include <bits/stdc++.h>
using namespace std;


int devideTwoInt(int dividend, int divisor){
    if(dividend == divisor) return 1;
    long ans = 0;

    bool sign = true;

    if(dividend >= 0 && divisor < 0) sign = false;
    else if(dividend < 0 && divisor > 0) sign = false;

    long n = abs(dividend);
    long d = abs(divisor);
    divisor = abs(divisor);
    while(n >= d){
        int cnt = 0;
        while(n >= (d << (cnt + 1))){
            cnt++;
        }
        ans = ans + (1<<cnt);
        n = n - (d * (1<<cnt));
    }

    if(ans == (1<<31) && sign == true)return INT_MAX;
    if(ans == (1 << 31) && sign == false)return INT_MIN;

    return sign? ans : (-1) * ans;
}
int main()
{
    int dividend, divisor;
    cout<<"Enter the dividend: ";
    cin>>dividend;
    cout<<"\nEnter the divisor: ";
    cin>>divisor;

    int ans = devideTwoInt(dividend, divisor);
    cout<<"\nQuotient is: "<<ans;
    return 0;
}