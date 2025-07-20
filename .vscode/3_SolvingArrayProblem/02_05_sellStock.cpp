#include<bits/stdc++.h>
using namespace std;
int stock(vector<int>arr,int n)
{
    int mini = arr[0];
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        int cost = arr[i]-mini;
        profit = max(profit,cost);
        mini = min(mini,arr[i]);
    }
    return profit;
}

//geek for geeks
    int maximumProfit(vector<int> &arr) {
        // code here
    int maxPro = 0;
    int n = arr.size();
    int lmin=arr[0];
    int lmax=arr[0];
    int i=0;
    
    while (i<=n-1) {
        while(i<n-1 && arr[i]>=arr[i+1]){
            i+=1;
            lmin=arr[i];
        }
        while(i<n-1 && arr[i]<=arr[i+1]){
            i+=1;
            lmax=arr[i];
        }
        
        maxPro+=(lmax-lmin);
    }
    
    return maxPro;
    }
int main()
{
    int n;
    cin>>n;
    int input;
    vector<int>a;
    for (int i = 0; i < n; i++)
    {
        cin>>input;
        a.push_back(input);
    }
    for(auto it = a.begin();it!=a.end();it++)
    {
        cout<< *(it)<<" ";
    }
    int result = maximumProfit(a);
    cout<<'\n'<<result;
    return 0;
}
