#include<bits/stdc++.h>
using namespace std;

int main()
{
multiset<int>ms;
ms.insert(10);//{10}
ms.insert(10);//{10,10}
ms.insert(10);//{10,10,10}

ms.erase(10);//all 10 will be erased
int cnt = ms.count(10);
//only one 10 will erase
ms.erase(ms.find(10));

return 0;
}