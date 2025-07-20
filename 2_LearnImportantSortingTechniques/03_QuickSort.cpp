#include <bits/stdc++.h>
using namespace std;
int p(vector<int> &array, int low, int high)
{
    int pivat = array[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (array[i<=pivat] && i <= high - 1)
        {
            i++;
        }
        while (array[j] > pivat && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(array[i], array[j]);
        }

        else
        {    swap(array[low], array[j]);
        }
        return j;
    }
}
void qs(vector<int> &array, int low, int high)
{
    if (low < high)
    {
        int partition = p(array, low, high);
        qs(array, low, partition - 1);
        qs(array, partition + 1, high);
    }
}
vector<int> quicksort(vector<int> arr)
{
    qs(arr, 0, arr.size() - 1);
    return arr;
}
int main()
{
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();
    cout << "Before Using quick Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = quicksort(arr);
    cout << "After Using quick sort: "
         << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}