#include <bits/stdc++.h>
using namespace std;

int priority(char op){
    if(op == '^') return 3;
    else if(op == '*' || op == '/') return 2;
    else if(op == '+' || op == '-') return 1;
    else return 0;
}

void infixToPostfix(string s){
    int i = 0;
    stack<char>st;
    string res = "";

    while(i < s.length()){
        if((s[i] >= 'a' && s[i] <= 'z')||
        (s[i] >= 'A' && s[i] <= 'Z')||
        (s[i] >= 0 && s[i] <= 9)){
            res+=s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                res+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && (priority(s[i]) <= priority(st.top()))){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    cout<<res;
}

int main()
{
    string s = "a+b*(c^d-e)";
    cout<<s<<endl;
    infixToPostfix(s);
    return 0;
}