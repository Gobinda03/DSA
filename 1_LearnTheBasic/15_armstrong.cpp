#include<bits/stdc++.h>
using namespace std;
bool checkArmstrong(int n){
	//Write your code here
	int num=n,ld,an=0,count=0;
	while(num!=0)
	{
		ld=num%10;
		num=num/10;
        count=count+1;
    }
	int num2 = n;
	while(num2!=0)
	{
		ld=num2%10;
		an+=pow(ld,count);
		num2=num2/10;
		
    }
	
	if(n==an) return 1;
	else return 0;
}
int main()
{
	int n;
	cin >> n;
	cout<<checkArmstrong(n);
	return 0;
}
