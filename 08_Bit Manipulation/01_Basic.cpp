#include <bits/stdc++.h>
using namespace std;


// Decimal to Binary
string convertDecimal2Binary(unsigned int n){
    string res = "";

    while(n>1){
        if(n%2 == 0) res+='0';
        else res+='1';
        n/=2;
    }
    if(n == 0) res+='0';
    else res+='1';

    reverse(res.begin(), res.end());
    return res;
}

// Binary to decimal
unsigned int convertBinary2Decimal(string binary){
    int n = binary.length();

    int powerOfTwo = 1, num = 0;
    for(int i = n-1 ; i >= 0 ; i--){
        if(binary[i] == '1'){
            num = num + powerOfTwo;
        }

        powerOfTwo *= 2;
    }
    return num;
}



int main()
{
    unsigned int n;
    cout<<"Enter the number u want to convert to binary: ";
    cin>>n;

    string binary = convertDecimal2Binary(n);
    cout<<n << " ===> "<<binary<<"\n";

    unsigned int decimal = convertBinary2Decimal(binary);
    cout<<binary << " ===> "<<decimal;

    cout<<"\n1's Complement of "<<n<<"===> "<<convertDecimal2Binary(~n);
    cout<<"\n2's Complement of "<<n<<"===> "<<convertDecimal2Binary(-n);
    return 0;
}