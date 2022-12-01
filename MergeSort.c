
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MergeSort(int *Array1, int low, int high, int size)
{
    int middle;
    if(low<high)
    {
        middle=(low+high)/2;
        printf(" something : %d",middle);
        MergeSort(Array1,low,middle,size);
        MergeSort(Array1,middle+1,high,size);
        Merge(Array1,low,middle,high,size);

    }
}

int Merge(int *Array1, int low, int middle, int high, int size)
{
    int i=low, m=middle+1, l=low, j, *Array2;
    Array2=(int*)malloc(size*sizeof(int));

    while(l<=middle && m<=high)
    {
        if(Array1[l]>=Array1[m])
        {
            Array2[i]=Array1[l];
            l++;
        }
        else
        {
            Array2[i]=Array1[m];
            m++;
        }
        i++;
    }

    if(l>middle)
    {
        for(j=m; j<=high; j++)
        {
            Array2[i]=Array1[j];
            i++;
        }
    }
    else
    {
        for(j=l; j<=middle; j++)
        {
            Array2[i]=Array1[j];
            i++;
        }
    }

    for(j=low; j<=high; j++)
    {
        Array1[j]=Array2[j];
    }

}

int main()
{
    printf("\t--MergeSort--\n\n");
    int i,*Array1,size=0;
    printf("Please give the size of the array : ");
    scanf("%d",&size);

    srand(time(NULL));
    Array1=(int*)malloc(size*sizeof(int));
    for(i=0; i<size; i++)
    {
        Array1[i]=rand()%20+1;
    }
    printf("\n\nThe array before the merge sort is : ");
    for(i=0; i<size; i++)
    {
        printf("%d ",Array1[i]);
    }

    MergeSort(Array1,0,size-1,size);

    printf("\n\nThe array after the merge sort is : ");
    for(i=0; i<size; i++)
    {
        printf("%d ",Array1[i]);
    }
    printf("\n\n");
}
