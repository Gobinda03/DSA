#include<bits/stdc++.h>
using namespace std;
//void
//Return
//Parameterised
//Non-Parameterised

void printname1()
{
    string name;
    cout<<"Enter the name"<<" ";
    cin>>name;
    cout<<name;
}
void printname2(string name)
{
    cout<<"Hey"<<" "<< name;
}
int sum(int a,int b)
{
    int s=a+b;
    return s;    
}

//pass by value
// int num(int n){
// cout << n <<endl;
// n+=5;
// cout << n <<endl;
// n+=5;
// cout << n <<endl;
// n+=5;

// }
//pass by reference
int num(int &n){
cout << n <<endl;
n+=5;
cout << n <<endl;
n+=5;
cout << n <<endl;
n+=5;

}
int main()
{
// printname1();
// cout<<endl;
// string name;
// cin>> name;
// printname2(name);
// int a,b;
// cout<<"Enter the value of a and b"<<endl;
// cin>>a>>b;
// int result = sum(a,b);
// cout<<result;
int number;
cout<<"Enter the number : "; 
cin>>number;
num(number);
cout << number;
return 0;
}