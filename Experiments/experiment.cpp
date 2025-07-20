#include<bits/stdc++.h>
using namespace std;

int countDigits(int n){
	// Write your code here.
	
	int cnt=0;
	while(n!=0){
		n=n/10;
		cnt++;
	}
	return cnt;
}

int main(){
	int n;
	cin>> n;
    cout<<countDigits(n);
    return 0;
}

