

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MergeSum(int *Array1,int left,int right)
{
    int middle=0;
    if(left==right) //�� � ������� ����� ���� �����, ������� ��� ���� ��� ���� �����.
    {
        return Array1[left];
    }
    middle=(left+right)/2; //������� ��� ���� ������ ���� ���� ��� ���������� ��� ���� ��� middle.
    /*��������� ��� ���������� ��� ���������� ���� (��� �����) ���� ��� ����� ���������.*/
    return Max1(MergeSum(Array1, left, middle), MergeSum(Array1, middle+1, right), MergeBothSum(Array1, left, middle, right));
}

int MergeBothSum(int *Array1, int left, int middle, int right)
{
    int i, maxs1=0, maxs2=0, sum=0;

    /*������� max �� ���� �� middle ��� ����� �� left.*/
    for(i=middle; i>=left; i--)
    {
        sum+=Array1[i];
        if(sum>maxs1)
        {
            maxs1=sum;
        }

    }
    sum=0;
    /*������� max �� ���� �� middle+1 ��� ����� �� right.*/
    for(i=middle+1; i<=right; i++)
    {
        sum+=Array1[i];
        if(sum>maxs2)
        {
            maxs2=sum;
        }
    }

    return maxs1+maxs2; //��������� �� ��������.
}

int Max2(int a,int b)
{
    return (a>b)?a:b;
}

int Max1(int a,int b,int c) //��������� ��� �� ������ �� max ����� �������.
{
    return Max2(Max2(a,b),c);
}

int main()
{
    int i,*Array1,sz=0, maxSum=0, l, r;

    printf("Please give the size of the array : ");
    scanf("%d",&sz);//����� ��� ��� ������ �� ������ �� ������� ��� ������.

    srand(time(NULL));
    Array1=(int*)malloc(sz*sizeof(int));//�������� �������� ����� ��� ��� ������.
    /*������ ��� ������ �� �������� �������� ��� �������� [-10,+10].*/
    for(i=0; i<sz; i++)
    {
        Array1[i]=rand()%20-10;
    }
    printf("\n\nThe Array is:\n");//�������� ��� ������.
    for(i=0; i<sz; i++)
    {
        printf("%d\t",Array1[i]);
    }
    l=0;
    r=sz-1;
    maxSum=MergeSum(Array1, l, r); //������ �� ��������� �� �� ������ �� ������� �������� ��� �� �� ����������� �� ��� ���������.

    printf("\n\nThe max sum of the array is: %d\n", maxSum); //��������� �� ����������.
}
