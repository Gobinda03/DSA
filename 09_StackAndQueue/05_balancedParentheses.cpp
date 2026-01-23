#include <bits/stdc++.h>
using namespace std;

bool balancedParentheses(string &s){
    int len = s.length();

    stack<char> st;
    for(int i = 0 ; i < len ; i++){
        if(s[i] == '(' ||s[i] == '['||s[i] == '{'){
            st.push(s[i]);
        }
        else{
            if(st.empty()) return false;
            char ch= st.top();
            if((ch == '(' && s[i] == ')' )|| (ch == '{' &&s[i] == '}') || (ch == '[' && s[i] == ']')) st.pop();
            else return false;
        }

    }
    return st.empty();
}
int main()
{
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    if (balancedParentheses(s)){
    cout<<"True" ;
    }
    else{
    cout<<"False";
    } 
    return 0;
}