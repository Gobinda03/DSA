#include<bits/stdc++.h>
using namespace std;

int main()
{
list<int >lS;
lS.push_back(6);
cout<<lS.size()<<endl;
lS.emplace_back(4);
cout<<lS.size();
lS.push_front(5);
lS.emplace_front();
cout<<endl;
// for (int i = 0; i < l.size(); i++)
// {
//     cout<< l[i];
// }
for (auto i = lS.begin(); i != lS.end(); i++)
{
    cout<<* i<<endl;
}

return 0;
}
//rest are same as vector