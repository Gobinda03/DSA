#include <bits/stdc++.h>
using namespace std;

string convertDecimal2Binary(int n){
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


// swap two numbers
void swapab(int a, int b){
    // int temp;

    // temp = a;
    // a = b;
    // b = temp;
    // cout<<"a = "<<a<<", "<<"b = "<<b<<"\n";

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout<<"a = "<<a<<", "<<"b = "<<b<<"\n";
}


// Check if the ith bit is set or not;
bool checkith(int num, int pos){
    // string binary = convertDecimal2Binary(num);

    //Traverse
    /*
    int i = binary.length() - pos - 1;
    if(binary[i] == '1') return true;
    else return false;
    */


    // Left shift
    /*
    if((num & (1 << pos)) != 0)return true;
    else false;
    */

    //Right shift
    if(((num >> pos)& 1) == 1) return true;
    else false;
}


// Set the ith bit
void setith(int num, int pos){
    string binary = convertDecimal2Binary(num);

    //Traverse
    /*
    int i = binary.length() - pos - 1;
    if(binary[i] == '0'){
        binary[i] = '1';
    }
    cout<<"\nAfter setting "<<pos<<"th bit: "<<binary;
    */

    // Left shift
    cout<<"\nAfter setting "<<pos<<"th bit: "<<convertDecimal2Binary(num | (1<<pos));  
}



// Clear the ith bit
void clearith(int num, int pos){
    string binary = convertDecimal2Binary(num);

    //Traverse
    /*
    int i = binary.length() - pos - 1;
    if(binary[i] == '1'){
        binary[i] = '0';
    }
    cout<<"\nAfter clearing "<<pos<<"th bit: "<<binary;
    */


    // Left shift
    cout<<"\nAfter clearing "<<pos<<"th bit: "<<convertDecimal2Binary(num & ~(1<<pos));  
}


// Toggle the ith bit
void toggleith(int num, int pos){
    string binary = convertDecimal2Binary(num);

    //Traverse
    /*
    int i = binary.length() - pos - 1;
    if(binary[i] == '1'){
        binary[i] = '0';
    }
    else{
        binary[i] = '1';
    }
    cout<<"\nAfter toggling "<<pos<<"th bit: "<<binary;
    */


    // Left shift
    cout<<"\nAfter toggling "<<pos<<"th bit: "<<convertDecimal2Binary(num ^ (1<<pos));  
}


// Remove last set bit
void removeLastSet(int num){
    string binary = convertDecimal2Binary(num);

    //Traverse
    /*
    int i = binary.length() - 1;

    while(i>=0){
        if(binary[i] == '1'){
            binary[i] = '0';
            break;
        }
        i--;
    }
    cout<<"\nAfter removing the "<<i<<"th(Last set bit) bit: "<<binary;
    */


    // Left shift
    cout<<"\nAfter removing the Last set bit: "<<convertDecimal2Binary(num & (num-1));
}

// Check if thenumber is a powerof two
bool isPowerOfTwo(int num){
    string binary = convertDecimal2Binary(num);

    //Traverse
    /*
    int cnt =0;
    int i = binary.length() - 1;

    while(i>0){
        if(binary[i] == '1'){
            cnt++;
        }
        i--;
    }
    if((cnt== 0) && (binary[i] == '1')) return true;
    else return false;
    */

    if((num & (num-1)) == 0) return true;
    else return false;
}


// Count the number of set bits
int countSetBits(int num){
    // bruteforce
    // int cnt = 0;
    // while(num>1){
    //     if(num%2 == 1) cnt++;
    //     num/=2;
    // }
    // if(num == 1) cnt++;
    // return cnt;
    
    // int cnt = 0;
    // while(num>1){
    //     cnt += num & 1;
    //     num = num >> 1;
    // }
    // if(num == 1) cnt++;
    // return cnt;


    int cnt = 0;
    while(num != 0){
        num = num & num-1;
        cnt++;
    }
    return cnt;
    
}

int main()
{
    int a, b;
    cout<<"Enter a number: ";
    cin>>a;
    cout<<"Enter another number: ";
    cin>>b;

    int pos;
    cout<<"Enter the position: ";
    cin>> pos;

    swapab(a, b);

    checkith(a, pos)?cout<<pos<<"th bit is set.":cout<<pos<<"th bit is not set.";

    setith(a, pos);

    clearith(a, pos);

    toggleith(a, pos);

    removeLastSet(a);

    isPowerOfTwo(a)?cout<<"It's a power of 2.":cout<<"It's not a power of 2.";

    cout<<"\nNumber of set bits in "<<a<<" is/are: "<<countSetBits(a);

    return 0;
}