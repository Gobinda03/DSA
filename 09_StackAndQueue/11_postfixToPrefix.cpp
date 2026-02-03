#include <bits/stdc++.h>
using namespace std;


// Postfix To Prefix
// Tc = O(N), SC = O(N)
string postfixToPrefix(string s){
    int i = 0;
    stack<string>st;

    while(i < s.length()){
        if((s[i] >= 'a' && s[i] <= 'z')||
        (s[i] >= 'A' && s[i] <= 'Z')||
        (s[i] >= '0' && s[i] <= '9')){
            st.push(string(1, s[i]));
        }else{
            if(st.size() < 2) return "";
            string op1 = st.top(); 
            st.pop();
            string op2 = st.top();
            st.pop();

            string eq =  s[i] + op2 + op1;
            st.push(eq);
        }
        i++;
    }

    return st.top();
}

int main()
{
    string s = "AB-DE+F*/";
    cout<<s<<endl;
    cout<<postfixToPrefix(s);
    return 0;
}