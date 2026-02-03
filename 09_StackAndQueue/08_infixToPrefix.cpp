#include <bits/stdc++.h>
using namespace std;

// Priority check
int priority(char op){
    if(op == '^') return 3;
    else if(op == '*' || op == '/') return 2;
    else if(op == '+' || op == '-') return 1;
    else return 0;
}


// Reverse the String
string rev(string &s){
    int n = s.length();

    for(int i = 0 ; i < n/2 ; i++){
        swap(s[i], s[n-i-1]);

        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] = '(';
        if(s[n-1-i] == '(') s[n-1-i] = ')';
        else if(s[n-i-1] == ')') s[n-i-1] = '(';
    }
    return s;
}


// Infix to prefix
// TC = O(3N)   SC = O(N)
void infixToPrefix(string s){

    s = rev(s);
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
            if(s[i] == '^'){
                while(!st.empty() && (priority(s[i]) <= priority(st.top()))){
                    res+=st.top();
                    st.pop();
                }
            }
            else{            
                while(!st.empty() && (priority(s[i]) < priority(st.top()))){
                    res+=st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    rev(res);
    cout<<res;
}

int main()
{
    string s = "(a+b)*c-d+e";
    cout<<s<<endl;
    infixToPrefix(s);
    return 0;
}