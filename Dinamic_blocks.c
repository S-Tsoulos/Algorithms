
#include <stdio.h>


int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
    int r[10]= {0,1,1,3,2,2,4,4,6,8};
    int value[10]= {4,3,7,5,2,8,6,3,1,7};
    int opt[11];
    int Same_Value=10;

    int i;
    opt[0]=0;
    printf(">1.First attemp with cutom value.\n");
    for (i=1; i<=10; i++)
    {
        opt[i]=max(opt[i-1],value[i-1]+opt[r[i-1]]);
    }
    printf("Max value for 10th cycle with custom values : %d\n\n",opt[10]);

    printf(">2.Second attemp with the same value.\n");


    for (i=1; i<=10; i++)
    {
        opt[i]=max(opt[i-1],Same_Value+opt[r[i-1]]);
    }
    printf("Max value for 10th cycle with same values : %d\n",opt[10]);




}



