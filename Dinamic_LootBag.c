
#include <stdio.h>

int main()
{
    int value[4][6];
    int keep[4][6];
    int ValuesT[3]={5,3,4};
    int WeightT[3]={3,2,1};

    int i,j,w;

    for(i=0;i<4;i++)
    {
        for(j=0;j<6;j++)
        {
            if(i==0 || j==0)
            {
                value[i][j]=0;
                keep[i][j]=0;
            }
            else if(j>=WeightT[i-1])//���� �� ��� ������ ��� ��� ��������� �� �������� ����������� ����� ���� �-1.
            {
                if(value[i-1][j]>ValuesT[i-1]+value[i-1][j-WeightT[i-1]])
                {
                    value[i][j]=value[i-1][j];
                    keep[i][j]=0;
                }
                else
                {
                    value[i][j]=ValuesT[i-1]+value[i-1][j-WeightT[i-1]];
                    keep[i][j]=1;
                }
            }
            else
            {
                value[i][j]=value[i-1][j];
                keep[i][j]=0;
            }
        }
    }

    printf("\n\n");
    printf("The Max price of the loot bag is : %d.\n" , value[3][5]);
    printf("The items that we take for the Max price of the loot bag are : \n");
    w=5;
    for(i=3;i>0;i--)
    {
        if(keep[i][w]==1)
        {
            printf(">Item : %d\n",i);
            printf("%d\n",WeightT[i]);
            w=w-WeightT[i-1];
            printf("%d\n",w);
        }
    }

}
