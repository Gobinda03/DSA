#include <bits/stdc++.h>
using namespace std;
int f(int a[], int n, int t)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == t)
        {
            return mid + 1;
        }
        else if (t > a[mid])
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int n, terget;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans;
    cout << "Target";
    cin >> terget;
    ans = f(arr, n, terget);
    cout << ans;

    return 0;
}