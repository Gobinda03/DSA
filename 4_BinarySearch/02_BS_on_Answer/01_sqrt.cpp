#include <bits/stdc++.h>
using namespace std;
int sqrtOf(int n){
    int low = 0, high = n/2, mid;
    int ans = 1;
    while(low<=high){
        mid = (low+high)/2;

        if((mid*mid)<=n){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>> n;

    cout<<"\nsqrt of "<<n<<" is: "<<sqrtOf(n);
    return 0;
}   