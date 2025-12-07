#include <bits/stdc++.h>
using namespace std;

double medianOfTwoArr(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size(), n2 = arr2.size();
    if (n1 > n2)
        return medianOfTwoArr(arr2, arr1);

    int low = 0, high = n1, mid1, mid2;
    int left = (n1 + n2 + 1) / 2;

    while (low <= high)
    {
        mid1 = (high + low) >> 1;
        mid2 = left - mid1;

        int l1 = (mid1 == 0) ? INT_MIN : arr1[mid1-1];
        int l2 = (mid2 == 0) ? INT_MIN : arr2[mid2-1];
        int r1 = (mid1 == n1) ? INT_MAX : arr1[mid1];
        int r2 = (mid2 == n2) ? INT_MAX : arr2[mid2];


        if (l1 <= r2 && r1 >= l2)
        {
            if ((n1 + n2) % 2 == 1)
            {
                return max(l1, l2);
            }
            else
                return ((max(l1, l2) + min(r1, r2)) / 2.0);
        }
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
}
int main()
{
    cout << "Enter the size of the first array: ";
    int n1;
    cin >> n1;

    cout << "First Array\n";
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter the size of the second array: ";
    int n2;
    cin >> n2;
    cout << "Second Array\n";
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    cout << "The midian of two given array is: " << medianOfTwoArr(arr1, arr2);
    return 0;
}