#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v;
    stack<int> st;
    st.push(5);     //{5}
    st.push(10);    //{10,5}
    st.push(15);    //{15,10,5}
    st.push(20);    //{20,15,10,5}
    st.emplace(25); //{25,20,15,10,5}
    // cout << "\nFirst element:";
    // cout << st.top() << endl;
    // cout << "size is :" << st.size() << endl;
    // st.pop();
    // cout << "now first elementis :" << st.top() << endl;

    // if (st.empty())
    // {
    //     cout << "empty";
    // }
    // cout << "not empty";

    for(int i = 0 ; i<3 ; i++){
        v.push_back(st.top());
        st.pop();
    }
    for(int i = 0 ; i<3 ; i++){
        cout<< v[i]<<" ";
    }
    return 0;
}