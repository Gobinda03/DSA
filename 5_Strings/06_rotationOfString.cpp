#include <bits/stdc++.h>
using namespace std;

bool isRotatedStringEqualToGoal(string str, string goal){
    if(str.length() != goal.length()) return false;

    for(int i = 0 ; i < str.length() ; i++){
        string s = str.substr(i) + str.substr(0, i);
        

        if(s == goal) return true;
    }
    return false;
}
int main()
{
    string str, goal;
    cout<<"String: ";
    cin>>str;
    cout<<"Goal: ";
    cin>>goal;
    isRotatedStringEqualToGoal(str, goal)? cout<<"True" : cout<<"False";
    return 0;
}