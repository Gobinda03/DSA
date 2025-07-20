#include <bits/stdc++.h>
using namespace std;
vector<int> findunion(int arr1[], int arr2[], int n, int m)
{
    set<int> s;
    vector<int> Union;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        s.insert(arr2[i]);
    }
    for (auto &it : s)
        Union.push_back(it);
    return Union;
}
vector<int> findInteraction(int arr1[], int arr2[], int n, int m)
{
    vector<int> ans;
    int vis[m] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < m; i++)
        {
            if (arr1[i] == arr2[j] && vis[j] == 0)
            {
                ans.push_back(arr1[i]);
                vis[j] = 1;
                break;
            }
            if (arr2[j] > arr1[i])
            {
                break;
            }
        }
    }
    return ans;
}
int main()
{
    int n = 8, m = 8;
    int arr1[] = {1, 1, 2, 3, 4, 5, 6, 7};
    int arr2[] = {2, 3, 4, 5, 6, 8, 9, 0};
    vector<int> u = findunion(arr1, arr2, n, m);
    for (auto &val : u)
    {
        cout << val << " ";
    }
    cout<<endl;
    vector<int> i = findInteraction(arr1, arr2, n, m);
    for (auto &res : i)
    {
        cout << res << " ";
    }

    return 0;
}