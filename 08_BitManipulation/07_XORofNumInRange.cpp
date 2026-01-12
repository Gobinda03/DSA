#include <bits/stdc++.h>
using namespace std;

int XORinRange(int range){
    if(range % 4 == 0) return range;
    else if(range % 4 == 1) return 1;
    else if(range % 4 == 2) return range + 1;
    else return 0; 
}

int main()
{
    int range;
    cout<< "Enter the Range: ";
    cin>>range;

    cout<<"XOR is "<<XORinRange(range)<<" from 1 to "<<range;
    return 0;
}