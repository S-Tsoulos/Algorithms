

#include <stdio.h>

int main()
{
    float A[8]= {2, 1, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01};
    float Value;
    int temp,i;

    printf("Give a value of EURO : ");
    scanf("%f",&Value);
    printf("\n");

    for(i=0; i<8; i++)
    {
        temp=Value/A[i];

        if(temp!=0)
        {

            printf("\n%d Coins about : %1.2f EURO.\n",temp,A[i]);
            Value=Value-temp*A[i];
            printf("Rest of the value : %1.2f.\n",Value);
        }
    }
}
