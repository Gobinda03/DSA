#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Traversal Operation
void show(int array[] , int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%3d",array[i]);
    }
    printf("\n");
}
int deletation(int myArray[],int Capacity,int size,int index)
{
    if (index >= Capacity)
    {
        return -1;
    }
    for (int i = index; i<size ; i++)
    {
        myArray[i]=myArray[i+1];

    }
    
}
int main()

{
    int myArray[10],size,index,element;
    printf("The size you need from the array\n");
    scanf("%d",&size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter the %d element",i+1);
        scanf("%d",&myArray[i]);
    }
    
    show(myArray,size);

    printf("Enter the position of element that u want to delete\n");
    scanf("%d",&index);

    deletation(myArray,10,size,index);

    show(myArray,size-1);

    return 0;
}