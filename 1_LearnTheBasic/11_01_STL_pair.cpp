#include<bits/stdc++.h>
using namespace std;
// pair
void pairing()
{
    pair<int , float> p = {5,2.5};
    cout<<p.first<<" "<<p.second;
    cout << endl;
    pair<long,pair<int , float>>q{12345,{10,5.5}};
    cout<<q.first<<" "<<q.second.first<<" "<<q.second.second;
    cout << endl;
    pair<int ,int>arr[]={{3,4},{5,6},{7,8}};
    cout<<arr[1].second;
}
int main()
{
pairing();
return 0;
}