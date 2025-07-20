#include<bits/stdc++.h>
using namespace std;
int removedup(int array[],int n)
{
    int j=0;
    for (int i = 1; i < n; i++)
    {
        if (array[i]!=array[j])
        {
            array[j+1]=array[i];
            j++;
        }
        
    }
    return j+1;
}

int main()
{
    int arr[10]={1,1,2,2,2,3,3,4,4,4};
    set<int>st;
for (int i = 0; i < 10; i++)
{
    st.insert(arr[i]);
}
int k=st.size();
cout<< "size of array"<< k<<endl;
int index=0;
for (int it:st)
{
    arr[index]=it;
    index++;
}
    cout<<k<<endl;

   int d= removedup(arr,10);
   for (int i = 0; i < k; i++)
   {
    cout<<arr[i]<< " ";
   }
   
return 0;
}