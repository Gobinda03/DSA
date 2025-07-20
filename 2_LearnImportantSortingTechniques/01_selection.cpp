#include <bits/stdc++.h>
using namespace std;
void selection(int array[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int min = i;
        for (int j = i+1; j <= n - 1; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        if (min!=i)
        {
            int temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
        
    }
}
//bubble sort
void bubble(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int didswap = 0;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didswap = 1;
            }
        }
        if (didswap == 0)
        {
            break;
        }
        else
            cout << " runs \n";
    }
}

//insertion sort
int main()
{
    int n;
    cout << "Size of array u need";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selection(arr,n);
    // bubble(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}