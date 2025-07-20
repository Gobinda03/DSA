#include<bits/stdc++.h>
using namespace std;

int main()
{
queue<int>q;
q.push(5);//{10}
q.push(20);//{10,20}
q.push(30);//{10,20,30}
q.emplace(40);//{10,20,30,40}
cout<<"first element : "<<q.front()<<endl;
q.front()+=5;
cout<<"now first element : "<<q.front()<<endl;
cout<<"last element : "<<q.back()<<endl;

q.pop();//{20,30,40}
cout<<"Now first element : "<<q.front()<<endl;
return 0;
}
//rest are same as stack