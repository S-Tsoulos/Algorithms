
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 3# Τριτη μεθοδολογια για να βρουμε την
ακολουθια Fibonacci με πινακα τριων θεσεων.*/
int Function3(int Array2[3],int n)
{
    int i;
    Array2[0]=0;
    Array2[1]=1;
    for (i=2; i<=n; i++)
    {
        Array2[2]=Array2[1]+Array2[0];
        Array2[0]=Array2[1];
        Array2[1]=Array2[2];
    }
    return Array2[2];
}

int main()
{
    printf("\t--Fibonacci--\n\n");
    int n,result3,Array2[3];
    clock_t start3,endclock3;
    double elapsed,elapsed2,elapsed3;
    printf("Please give the number of N :");
    scanf("%d",&n);
    printf("\n");
    result2=Function2(Array,n);
    endclock2 = clock();
    elapsed2 = ((double) (endclock2 - start2)) / CLOCKS_PER_SEC;
    start3 = clock();
    result3=Function3(Array2,n);
    endclock3 = clock();
    elapsed3 = ((double) (endclock3 - start3)) / CLOCKS_PER_SEC;
    printf("The result is %d with the method 3#.\n",result3);
    printf("The time for the third method is %f.\n\n",elapsed3);
}
