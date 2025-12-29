#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int level = 0;

        for(auto ch : s){
            if(ch == '('){
                if(level > 0){
                    result += ch;
                }
                level++;
            }

            if(ch == ')'){
                level--;

                if(level > 0){
                    result += ch;
                }
            }
        }
        return result;
    }


    
};



int main(){
    Solution sol;
    string str;
    cout << "Enter the string: ";
    cin >>str;
    cout<<"Your input: "<<str;
    cout<<"\nOutput: "<<sol.removeOuterParentheses(str);
    return 0;
}