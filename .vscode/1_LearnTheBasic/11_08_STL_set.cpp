#include<bits/stdc++.h>
using namespace std;

int main()
{
set<int>st;
st.insert(20);//{20}
st.insert(10);//{10,20}
st.emplace(20);//{10,20} /*it will not print 20 again*/
st.insert(30);//{10,20,30}
for (auto i = st.begin(); i != st.end(); i++)
{
    cout<< * i<<" ";
}
cout<<endl;

if(st.find(15)!=st.end())
{cout<< "15 is present."<<endl;}
else 
cout<<"not present"<<endl;
/*st.erase(20);
for (auto i = st.begin(); i != st.end(); i++)
{
    cout<< * i<<" ";
}*/
cout<<endl;
int cnt=st.count(1);
cout<< cnt<<endl;
auto it1=st.find(10);
auto it2=st.find(20);
st.erase(it1,it2);
for (auto i = st.begin(); i != st.end(); i++)
{
    cout<< * i<<" ";
}
return 0;
}