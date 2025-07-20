#include<bits/stdc++.h>
using namespace std;

int main()
{
    //priority max to min
priority_queue<int>pqa;
pqa.push(20);//{20}
pqa.push(30);//(30,20)
pqa.push(10);//(30,20,10)
pqa.emplace(40);//(40,30,20,10)
cout<<"here priority element is: "<<pqa.top()<<endl;
pqa.pop();
cout<<"now priority element is: "<<pqa.top()<<endl;

//priority min to max
priority_queue<int,vector<int>,greater<int>>pqb;
pqb.push(20);//{20}
pqb.push(30);//(20,30)
pqb.push(10);//(10,20,30)
pqb.emplace(40);//(10,20,30,40}
cout<<"here priority element is: "<<pqb.top()<<endl;
pqb.pop();
cout<<"now priority element is: "<<pqb.top();

return 0;
}