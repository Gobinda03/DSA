#include<stdio.h>

int linearsearch(int array[],int size,int element)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i]==element)
        {
            return i;
        }
    }
        return -1;
    
}
int main()
{
    int myarray[10]={2,5,8,7,6,1,9,3,4,10},element,index;
    int size = sizeof(myarray)/sizeof(int);
    element=12;
    int searchindex = linearsearch(myarray,size,element);
    printf("The element %d found in %d index",element,searchindex);
    return 0;
}