#include <bits/stdc++.h>
using namespace std;
// better Approach
int sortt(vector<int> &arr, int n)
{
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            cnt0++;
        }
        else if (arr[i] == 1)
        {
            cnt1++;
        }
        else
        {
            cnt2++;
        }
    }
    for (int i = 0; i < cnt0; i++)
        arr[i] = 0;
    for (int i = cnt0; i < cnt0 + cnt1; i++)
        arr[i] = 1;
    for (int i = cnt0 + cnt1; i < n; i++)
        arr[i] = 2;
}
// Optimal
int sorttt(vector<int> &arr, int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {

        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[high], arr[mid]);
            high--;
        }
    }
}
int main()
{
    vector<int> a = {0, 0, 1, 0, 1, 0, 2, 0, 2, 2};
    int n = a.size();
    sortt(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    sorttt(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}