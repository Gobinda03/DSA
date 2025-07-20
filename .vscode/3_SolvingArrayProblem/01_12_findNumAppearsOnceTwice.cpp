#include <bits/stdc++.h>
using namespace std;
// Brute Force solution
int getSingleElement1(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == num)
            {
                cnt++;
            }
        }
        if (cnt == 1)
        {
            return num;
        }
    }
    return -1;
}
// Better Aprroach
int getSingleElement2(vector<int> arr, int n)
{
    int maxi = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    int hash[maxi + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] == 1)
        {
            return arr[i];
        }
    }
    return -1;
}
// Better Approach 2
int getSingleElement3(vector<int> arr, int n)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
    return -1;
}
// Optimal Approach
int getSingleElement4(vector<int> arr, int n)
{

    int xorr = 0;
    for (int i = 0; i < n; i++)
    {
        xorr = xorr ^ arr[i];
    }
    if (xorr == 0)
    {
        return -1;
    }
    else return xorr;
}
int main()
{
    vector<int> arr = {1, 1, 2, 3, 3};
    int size = arr.size();
    int ans1 = getSingleElement1(arr, size);
    int ans2 = getSingleElement2(arr, size);
    int ans3 = getSingleElement3(arr, size);
    int ans4 = getSingleElement4(arr, size);
    cout << "The single element is :" << ans1;
    cout << "\nThe single element is :" << ans2;
    cout << "\nThe single element is :" << ans3;
    cout << "\nThe single element is :" << ans4;
    return 0;
}