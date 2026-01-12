#include <bits/stdc++.h>
using namespace std;

int flippedBit(int start, int goal){
    int ans = start ^ goal;

    int cnt = 0;
    while(ans != 0){
        ans = ans & (ans-1);
        cnt++;
    }

    return cnt;
}
int main()
{
    int start, goal;

    cout<<"Enter the Start and Goal: ";
    cin>>start>>goal;

    cout<<start<<"\n"<<goal;
    cout<<"To reach the Goal ("<<goal<<") we need to flip "<<flippedBit(start, goal)<<" bits from start("<<start<<")";

    return 0;
}