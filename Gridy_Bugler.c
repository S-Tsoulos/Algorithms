

#include <stdio.h>

int main()
{
    printf("\tThe Bugler Bag.");
    int W[5]= {7, 8, 9, 2, 6};
    int V[5]= {5, 3, 9, 5, 7};
    float Ratio[5]= {0, 0, 0, 0, 0};
    int Bag=20,Sum_Value=0,i,j;

    int temp=0;

    for(i=0; i<5; i++)
    {
        Ratio[i]=(float)V[i]/W[i];
    }



    for(i=0; i<5; i++)
    {
        for (j=i+1; j<5; j++)
        {
            if(Ratio[j]>Ratio[i])
            {
                temp=Ratio[j];
                Ratio[j]=Ratio[i];
                Ratio[i]=temp;

                temp=V[j];
                V[j]=V[i];
                V[i]=temp;

                temp=W[j];
                W[j]=W[i];
                W[i]=temp;
            }
        }
    }

    i=0;
    while (Bag>0 && i<5)
    {
        if(W[i]<Bag)
        {
            Sum_Value=Sum_Value+V[i];
            Bag=Bag-W[i];
        }
        i++;
    }

    printf("\n");
    printf("\nThe full value of the bag is : %d.   Bag Space : %d.\n", Sum_Value, Bag);
}

