#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int result(int array[], int size, int element)
{

    int low, high, mid;
    low =0;
    high =size-1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (element == array[mid])
        {
            return mid;
        }
        if (array[mid] > element)
        {
            high =mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -2;
}
int main()
{
    int myArray[10]={2,4,6,8,10,12,14,16,18,20}, size, element;
    // printf("Enter the space you want from myArray\n");
    // scanf("%d", &size);
    // for (int i = 0; i < size; i++)
    // {
    //     printf("Your %d element is: ", i + 1);
    //     scanf("%d", &myArray[i]);
    // }
   

     printf("Enter the element u want to find out\n");
    scanf("%d", &element);
    int indexsearch =result(myArray,10,element);
    printf("Your Element %d is in %d th position",element,indexsearch+1);
    return 0;
}