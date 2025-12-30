#include <bits/stdc++.h>
using namespace std;

string reverseString(string s) {
    string word = "";
    vector<string>sentence;

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] != ' '){
            word += s[i];
        }
        else if(!word.empty()){
            sentence.push_back(word);
            word = "";
        }
    }
    if(!word.empty()){
        sentence.push_back(word);
    }

    reverse(sentence.begin(), sentence.end());

    string result = "";
    for(int i = 0 ; i < sentence.size() ; i++){
        result += sentence[i];
        if(i < sentence.size()-1){
            result += " ";
        }
    }

    return result;
}


string reverseStringOptimal(string s) {
    string result = "";
    int i = s.length();

    while(i >= 0){

        while(i >=0 && s[i] == ' '){
            i--;
        }
        if (i < 0) break;
        int end = i;
        while(i >= 0 && s[i] != ' '){
            i--;
        }

        string word = s.substr(i+1, end - i);

        if(!result.empty()){
            result+=" ";
        }
        result+= word;
    }

    return result;
}



int main(){
    string str;
    cout << "Enter the string: ";
    getline(cin, str);
    cout<<"Your input: "<<str;
    cout<<"\nOutput: "<<reverseString(str);
    cout<<"\nOutput: "<<reverseStringOptimal(str);
    return 0;
}