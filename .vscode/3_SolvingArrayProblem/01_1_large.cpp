#include <bits/stdc++.h>
using namespace std;
int l(int array[], int start, int end)
{
    int large = array[0];
    for (int i = 0; i < end; i++)
    {
        if (large < array[i])
        {
            large = array[i];
        }
    }
    return large;
}
int largestElement(vector<int> &arr, int n) {

  // Write your code here.

   

   int max =arr[0];

   

   for(int i = 0;i<n; i++)

   {

     if (arr[i] > max) {

       max = arr[i];

     }

   }

   return max;

}

 
int main()
{
    int n;
    cout << "Enter the size of the array :";
    cin >> n;
    cout << endl;
    int arr[n];
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nYour array is :";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    int large = l(arr, 0, n);
    cout << endl;
    cout << "\nThe Largest element of the array is :" << large;
    return 0;
}
