#include <bits/stdc++.h>
using namespace std;

void margesort(vector<int> &array, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (array[left] <= array[right])
        {
            temp.push_back(array[left]);
            left += 1;
        }
        else
        {
            temp.push_back(array[right]);
            right += 1;
        }
    }
    while (left <= mid)
        {
            temp.push_back(array[left]);
            left++;
        }
    while (right <= high)
        {
            temp.push_back(array[right]);
            right++;
        }
        for (int i = low; i <= high; i++)
        {
            array[i]=temp[i-low];
        }
}
void marge(vector<int> &array, int low, int high)
{
    if (low >= high) return;
    int mid = (low + high) / 2;
    marge(array, low, mid);
    marge(array, mid + 1, high);
    margesort(array, low, mid, high);
}
int main()
{
    vector<int>array={5,6,7,1,2,3,3,4,9,8};
    int n=10;
    cout<< " Before sorting:";
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
    cout << endl;
    marge(array,0,9);
    cout<<"after sorting the array: ";
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
        return 0;
}