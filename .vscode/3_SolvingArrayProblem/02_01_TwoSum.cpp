#include <bits/stdc++.h>
using namespace std;
//Brute Force
string findSum1(vector<int> &a, int sum)
{
    int n=a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == sum)
            {
                return "YES";
            }
        }
    }
    return "NO";
}
//Better Approach
string findSum2(vector<int> &a, int sum)
{
    int n= a.size();
    unordered_map<int,int>mp;
    for (int i = 0; i < n; i++)
    {
        int num=a[i];
        int needed=sum-num;
        if (mp.find(needed)!=mp.end())
        {
            return "Yes";
        }
        mp[num]=i;
    }
    return "NO";
    
}
//Optimal
string findSum3(vector<int> &a, int sum)
{
    int n=a.size();
    int left =0,right=n-1;
    sort(a.begin(),a.end());
    while (left<right)
    {
        int s=a[left]+a[right];
        if (s==sum)
        {
            return "YES";
        }
        else if(s<sum) left++;
        else right--;
    }
    return "NO";
    
}

int main()
{
    vector<int> a = {575, 330, 339, 584 ,239 ,31 ,173, 929 ,967};
    int n = a.size();
    int sum = 204;
    string ans1 = findSum1(a, sum);
    string ans2 = findSum2(a, sum);
    string ans3 = findSum3(a, sum);
    cout << ans1;
    cout<<endl;
    cout << ans2;
    cout<<endl;
    cout << ans3;
    return 0;
}