#include <bits/stdc++.h>
using namespace std;


string largestOddNumber(string s) {
    int n = s.length();
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        if (start <= end && s[start] == '0') {
            start++;
            continue;
        }
        
        if (end >= 0 && (s[end] - '0') % 2 == 0) {
            end--;
            continue;
        }
        
        if (start <= end && (s[end] - '0') % 2 == 1) {
            return s.substr(start, end - start + 1);
        }
    }
    return "";
}




int main(){
    string str;
    cout << "Enter the string: ";
    getline(cin, str);
    cout<<"Your input: "<<str;
    cout<<"\nOutput: "<<largestOddNumber(str);
    return 0;
}