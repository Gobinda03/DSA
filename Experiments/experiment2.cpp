#include<bits/stdc++.h>
using namespace std ;

void mergeSort(vector<int> &arr, int n) {
  margesortt(arr,0,n);

}
void margesortt(vector<int> &arr, int low, int high) {
  if (low >= high) return;
  int mid = (low + high) / 2;
  margesortt(arr, low, mid);
  margesortt(arr, mid + 1, high);
  marge(arr, low, mid, high);
}
void marge(vector<int> &array, int low, int mid, int high)
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
int main()
{
    vector<int>s;
    int v=0;
    for (int i = 0; i < 5; i++)
    {
        cin>>v;
        s.emplace_back(v);
    }
    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout<< *i<<" ";
    }
    mergeSort(s,5);
    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout<< *i;
    }
    
    

    return 0;
   
}