#include <bits/stdc++.h>
using namespace std;


string longestCommonPrefix(vector<string> &s) {
    int n = s.size();
    sort(s.begin(), s.end());
    string first = s[0];
    string last = s[n - 1];
    string result = "";
    int size = (first.end() - first.begin());

    for(int i = 0 ; i < size ; i++){
        if(first[i] != last[i]) break;

        result += first[i];
        i++;
    }
    return result;
}




int main(){
    vector<string> str;
    int n;
    cin>> n;
    for(int i = 0 ; i < n ; i++){
        cin>>str[i];
    }
    cout<<"Your input: ";
    for(auto s : str){
        cout<<s;
    }
    cout<<"\nOutput: "<<longestCommonPrefix(str);
    return 0;
}