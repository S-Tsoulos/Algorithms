

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int sz, *Array,i,Max,tempmax;
    printf("\t--Max Sum--");
    srand(time(NULL));
    printf("\n\nPlease give the size of the array : ");
    scanf("%d",&sz);//����� ��� ��� ������ �� ������ �� ������� ��� ������.

    Array=(int*)malloc(sz*sizeof(int));//����� �������� ��� ����� ��� ������.

    for(i=0; i<sz; i++)
    {
        Array[i]=rand()%20-10;//������ �� �������� �������� ��� �������� [-25,25].
    }

    printf("\n\nThe array has the following numbers :\n");//�������� ��� ������.
    for(i=0; i<sz; i++)
    {
        printf("%d\t",Array[i]);
    }

    /*����� ��� ��������� ������� ��� ��
      Max ��� ����� �� ������ ����������.
      �������� ��� ��� ������ ��� ������ �� �������
      �������� ��� ����������� ������ ��� �� �������� ���.*/
    tempmax=Array[0];
    Max=Array[0];
    for(i=1; i<sz; i++)
    {
        tempmax=MaxFunction(Array[i],Array[i]+tempmax);
        Max=MaxFunction(Max,tempmax);
    }

    printf("\n\nMax Sum :%d.\n",Max);//�������� �� ������� ��������.

}

/*��������� ��� ������� ��� ������� ������ ��� �������.*/
int MaxFunction(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
