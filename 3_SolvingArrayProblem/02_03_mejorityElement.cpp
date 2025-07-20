#include <bits/stdc++.h>
using namespace std;
int mejority1(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; i++)
        {
            if (a[i] == a[j])
            {
                cnt++;
            }

            if (cnt > (n / 3))
            {
                return a[i];
            }
        }
    }
    return -1;
}
int mejority2(vector<int> &a)
{
    int maxi = 0;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, a[i]);
    }
    int hash[maxi + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (hash[a[i]] > (n / 2))
        {
            return a[i];
        }
    }
    return -1;
}
int mejority3(vector<int> &a)
{
    map<int, int> mp;
    for (int i = 0; i < a.size(); i++)
    {
        mp[a[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second > (a.size() / 2))
        {
            return it.first;
        }
    }
    return -1;
}
int main()
{
    vector<int> a;
    int n = 7, v = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the " << i + 1 << " element :";
        cin >> v;
        a.push_back(v);
    }
    // for (int i = 0; i<n; i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    for (auto it = a.begin(); it != a.end(); it++)
    {
        cout << *it << " ";
    }

    int result1 = mejority1(a);
    int result2 = mejority2(a);
    int result3 = mejority3(a);
    cout << endl
         << "Result :" << result1;
    cout << endl
         << "Result :" << result2;
    cout << endl
         << "Result :" << result3;
    return 0;
}