#include<bits/stdc++.h>
using namespace std;

int main()
{
deque<int>dq;
dq.push_back(5);//{5}
dq.emplace_back(10);//{5,10}
dq.push_front(15);//{15,5,10}
dq.emplace_front(20);//{20,15,5,10}
cout<< "size" << dq.size()<<endl;
cout <<" before"<<endl;
for (auto i = dq.begin(); i != dq.end(); i++)
{
    cout<< *i <<endl;
}

dq.pop_back();//{20,15,5}
dq.pop_front();//{15,5}
cout<<"After"<<endl;
for (auto i = dq.begin(); i != dq.end(); i++)
{
    cout<< *i <<endl;
}
cout<< "size" << dq.size();
return 0;
}
//rest as same as vector